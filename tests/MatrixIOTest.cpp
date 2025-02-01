#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <cstdio>
#include <fstream>
#include "../src/matrixIO.hpp"

#define BOOST_TEST_DYN_LINK

using namespace Eigen;
using namespace std;
using namespace matrixIO;

// Function to delete CSV file after testing
void deleteTestCSV(const string &filename)
{
  remove(filename.c_str());
}

BOOST_AUTO_TEST_SUITE(MatrixIOTests, *boost::unit_test::tolerance(1e-5))

// Function tests if read csv data is as expected
BOOST_AUTO_TEST_CASE(TestOpenData)
{
  string testFileName = "tests/test_matrix.csv";

  MatrixXd expectedMatrix(3, 3);
  expectedMatrix << 1.232, 2.112, 3.312,
      4.312, 5.367, 6.495,
      7.212, 8.749, 9.363;

  saveData(testFileName, expectedMatrix);

  MatrixXd result = openData(testFileName, 3);

  // Check if read values are as expected
  BOOST_CHECK(result.isApprox(expectedMatrix));

  // Temp file deleted after checking
  deleteTestCSV(testFileName);
}

BOOST_AUTO_TEST_SUITE_END()