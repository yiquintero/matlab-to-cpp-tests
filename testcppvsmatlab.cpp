#include <gtest/gtest.h>
#include "Eigen/Dense"
#include <fstream>
#include <sstream>
#include <string>

using namespace Eigen;
using namespace std;

// Utility function to read a matrix from a CSV file
MatrixXd readMatrixFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file: " + filename);
    }

    vector<vector<double>> values;
    string line;
    while (getline(file, line)) {
        stringstream lineStream(line);
        string cell;
        vector<double> row;
        while (getline(lineStream, cell, ',')) {
            row.push_back(stod(cell));
        }
        values.push_back(row);
    }

    size_t rows = values.size();
    size_t cols = rows > 0 ? values[0].size() : 0;
    MatrixXd matrix(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            matrix(i, j) = values[i][j];
        }
    }

    return matrix;
}

// Test fixture class
class TestCppVsMatlab : public ::testing::Test {
protected:
    MatrixXd matlabA, matlabB, matlabC;
    MatrixXd cppA, cppB, cppC;

    void SetUp() override {
        // Read matrices generated by MATLAB
        matlabA = readMatrixFromCSV("../data/A_matlab.dat");
        matlabB = readMatrixFromCSV("../data/B_matlab.dat");
        matlabC = readMatrixFromCSV("../data/C_matlab.dat");

        // Read matrices generated by C++
        cppA = readMatrixFromCSV("../data/A_cpp.dat");
        cppB = readMatrixFromCSV("../data/B_cpp.dat");
        cppC = readMatrixFromCSV("../data/C_cpp.dat");
    }
};

// Test 1: Compare matrix A between MATLAB and C++
TEST_F(TestCppVsMatlab, CompareMatrixA) {
    ASSERT_EQ(matlabA.rows(), cppA.rows()) << "Row mismatch in A";
    ASSERT_EQ(matlabA.cols(), cppA.cols()) << "Column mismatch in A";
    EXPECT_FALSE(matlabA.isApprox(cppA, 1e-9)) << "Matrix A is not approximately equal";
}

// Test 2: Compare matrix B between MATLAB and C++
TEST_F(TestCppVsMatlab, CompareMatrixB) {
    ASSERT_EQ(matlabB.rows(), cppB.rows()) << "Row mismatch in B";
    ASSERT_EQ(matlabB.cols(), cppB.cols()) << "Column mismatch in B";
    EXPECT_TRUE(matlabB.isApprox(cppB, 1e-9)) << "Matrix B is not approximately equal";
}

// Test 3: Compare C.dat between MATLAB and C++
TEST_F(TestCppVsMatlab, CompareMatrixC) {
    ASSERT_EQ(matlabC.rows(), cppC.rows()) << "Row mismatch in C";
    ASSERT_EQ(matlabC.cols(), cppC.cols()) << "Column mismatch in C";
    EXPECT_TRUE(matlabC.isApprox(cppC, 1e-9)) << "Matrix C is not approximately equal";
}

// Test 4: Compare Matix A and B
TEST_F(TestCppVsMatlab, ComparaMatrixAB) {
    EXPECT_FALSE(matlabA.isApprox(matlabB, 1e-9)) << "Matrix A is the same as matrix B";
}


// Other types of tests

// Test: No exceptions are thrown i.e. function does not fail
TEST_F(TestCppVsMatlab, readMatrixFromCSVDoesNotThrowException) {
    EXPECT_NO_THROW(readMatrixFromCSV("../data/A_matlab.dat"));
}

// Test: Exception is thrown i.e. function fails as expected
TEST_F(TestCppVsMatlab, readMatrixFromCSVThrowsException) {
    EXPECT_THROW(readMatrixFromCSV("../data/non_existing_file.dat"), std::runtime_error);
}