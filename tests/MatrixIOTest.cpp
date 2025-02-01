#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <cstdio>
#include <fstream>
#include "../src/matrixIO.hpp"
#include "Configuration.hpp"

#define BOOST_TEST_DYN_LINK

using namespace Eigen;
using namespace std;
using namespace matrixIO;

BOOST_AUTO_TEST_SUITE(MatrixIOTests, *boost::unit_test::tolerance(1e-5))

// Function tests if read csv data is as expected
BOOST_AUTO_TEST_CASE(TestOpenData)
{
  string testFileName = "data/test_matrix.csv";

  MatrixXd expectedMatrix(3, 3);
  expectedMatrix << 0.680375, 0.59688, -0.329554,
      -0.211234, 0.823295, 0.536459,
      0.566198, -0.604897, -0.444451;

  Configuration configuration{"testconfig.yml"};

  MatrixXd result = openData(configuration.MatrixFileName, configuration.MatrixSize);

  // Check if read values are as expected
  BOOST_CHECK(result.isApprox(expectedMatrix));
}

BOOST_AUTO_TEST_SUITE_END()