//Christine Ma cm4927
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
	if (argc != 3){
		printf("Incorrect Number of Arguments");
		return 0;
	}
	//argv [0] = program name
	//argv[1] = num
	//argv[2] = filename
	//Take in a file and number of generation
	int generations = atoi (argv[1]);
	//get the file name and open it and add .out
	FILE *f = fopen(argv[2], "r");
	//make a new string that concatenates the string of argv[2] + out
	char str1[15];
	strcpy(str1, argv[2]);
	strcat(str1,".out");
	FILE *out = fopen(str1, "w");
	int matrix[5][5];

	//Read in the matrix that is 5x5
	for (int r = 0; r < 5; r++){ //Row
		for (int c = 0; c < 5; c++){ //Column
			fscanf(f, "%d", &matrix[r][c]);
		}
	}

	int alive = 1, dead = 0;
	int neighbor_counter[5][5];
	for (int g = 0; g < generations; g++){
		for (int r = 0; r < 5; r++){ //Row
			for (int c = 0; c < 5; c++){ //Column
				int up = r-1;
				int down = r+1;
				int left = c-1;
				int right = c+1;
				int neighbors = 0;
					//check up
				if (up > -1){
					if (matrix[up][c] == alive){
						neighbors++;
					}
					//check up left
					if (left > -1){
						if (matrix[up][left] == alive){
							neighbors++;
						}
					}

					//check up right
					if (right < 6){
						if (matrix[up][right] == alive){
							neighbors++;
						}
					}
				}
				//check left
				if (left > -1){
					if (matrix[r][left] == alive){
						neighbors++;
					}
				}
				//check right
				if (right < 6){
					if (matrix[r][right] == alive){
						neighbors++;
					}
				}
				//check down
				if (down < 6){
					if (matrix[down][c] == alive){
						neighbors++;
					}

					//check down left
					if (left > -1){
						if (matrix[down][left] == alive){
							neighbors++;
						}
					}
					//check down right
					if (right < 6){
						if (matrix[down][right] == alive){
							neighbors++;
						}

					}
				}
				neighbor_counter[r][c]= neighbors;
			}
		}
		//Compare how many neighbors each unit has and whther they will be alive or dead for the next generation
		for (int r = 0; r < 5; r++){ //Row
			for (int c = 0; c < 5; c++){ //Column
				if (matrix[r][c]==alive){
					if ((neighbor_counter[r][c]!=2) && (neighbor_counter[r][c]!=3) ){
						matrix[r][c]= dead;
					}
				}
				if (matrix[r][c]== dead){
					if (neighbor_counter[r][c] == 3){
						matrix[r][c]= alive;
					}
				}
				neighbor_counter[r][c] = 0; //reset the number of neighbors for the next generation
			}
		}
	}
	//Write to file the matrix representing the last generation
		for (int r = 0; r < 5; r++){ //Row
			for (int c = 0; c < 5; c++){ //Column
				fprintf(out, "%d ", matrix[r][c]);
			}
			fprintf(out, "\n");
		}
		fclose(f);
		fclose(out);
	}
