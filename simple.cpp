#include <vector>
#include <boost/python.hpp>
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace boost::python;
namespace {
    class JsonWriter
    {
        public:
            //void add_number(double num) {
                //this->numbers.push_back(num);
            //}
            const char * get_json_str() {
                using namespace rapidjson;
                Document doc;
                doc.SetArray();
                // Document::AllocatorType& allocator = doc.GetAllocator();
                //StringBuffer buffer;
                //Writer<StringBuffer> writer(buffer);
                //doc.Reserve(kNumberType * this->numbers.size(), allocator);
                //for (double item : this->numbers) {
                    //doc.PushBack(item, allocator);
                //}
                //doc.Accept(writer);
                return "Hello";
                //return buffer.GetString();
            }
        //private:
            //std::vector<double> numbers;
    };

    const char* greet() { 
        using namespace rapidjson;
        Document doc;
        doc.SetArray();
        StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        doc.Accept(writer);
        return buffer.GetString();
    }
}

BOOST_PYTHON_MODULE(simple)
{
    class_<JsonWriter>("JsonWriter")
        //.def("add_number", &JsonWriter::add_number) 
        .def("get_json_str", &JsonWriter::get_json_str)
    ;
    def("greet", greet);
}
