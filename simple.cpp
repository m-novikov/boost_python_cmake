#include <string>
#include <boost/python.hpp>

using namespace boost::python;

std::string greet() { return "Hello, World!"; }
int square(int number) { return number * number; }
BOOST_PYTHON_MODULE(simple)
{
    def("greet", greet);
    def("square", square);
}
