#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "matrixIO.hpp"

using namespace std;
using namespace Eigen;

BOOST_AUTO_TEST_SUITE(OpenDataTests)

BOOST_AUTO_TEST_CASE(MatrixColNeqMatrixSize)
{
  string filepath = "../data/m3.csv";

  BOOST_CHECK_THROW(matrixIO::openData(filepath, 4), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(MatrixRowNeqMatrixSize)
{
  string filepath = "../data/m3x4-testing.csv";

  BOOST_CHECK_THROW(matrixIO::openData(filepath, 4), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(MatrixValidData)
{
  string filepath = "../data/m3.csv";

  MatrixXd result = matrixIO::openData(filepath, 3);

  BOOST_REQUIRE_EQUAL(result.rows(), 3);
  BOOST_REQUIRE_EQUAL(result.cols(), 3);

  BOOST_CHECK_CLOSE(result(0, 0), 0.680375, 0.001);
  BOOST_CHECK_CLOSE(result(0, 1), 0.59688, 0.001);
  BOOST_CHECK_CLOSE(result(0, 2), -0.329554, 0.001);
  BOOST_CHECK_CLOSE(result(1, 0), -0.211234, 0.001);
  BOOST_CHECK_CLOSE(result(1, 1), 0.823295, 0.001);
  BOOST_CHECK_CLOSE(result(1, 2), 0.536459, 0.001);
  BOOST_CHECK_CLOSE(result(2, 0), 0.566198, 0.001);
  BOOST_CHECK_CLOSE(result(2, 1), -0.604897, 0.001);
  BOOST_CHECK_CLOSE(result(2, 2), -0.444451, 0.001);
}

BOOST_AUTO_TEST_SUITE_END()
