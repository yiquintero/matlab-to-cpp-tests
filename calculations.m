% calculations, maths, etc.

% Define matrices A and B
A = [1, 2, 3;
 4, 5, 6;
  7, 8, 9];
B = [9, 8, 7; 6, 5, 4; 3, 2, 1];

% Write matrices A and B to CSV files for testing
csvwrite('A_matlab.dat', A);
csvwrite('B_matlab.dat', B);

% Calculate matrix C as the product of A and B
C = A * B;

% Write matrix C to a CSV file for testing
csvwrite('C_matlab.dat', C);

disp('Matrices A, B, and their product C have been saved to CSV files.');