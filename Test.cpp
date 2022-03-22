#include "doctest.h"
#include "Notebook.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;


TEST_CASE("Good input") {
    ariel::Notebook notebook;
    //1
	notebook.write(0,0,0, Direction::Horizontal, "abcd");
    CHECK(notebook.read(0,0, 0, Direction::Horizontal,4) == "abcd");
    //2
    notebook.write(0, 1,0, Direction::Vertical, "einav");
    CHECK(notebook.read(0,1, 0, Direction::Vertical,5) == "einav");
    //3
    notebook.write(0,2,0, Direction::Horizontal, " ");
    CHECK(notebook.read(0,2, 0, Direction::Horizontal,1) == " ");
    //4
    notebook.write(0,3,0, Direction::Horizontal, "hi my name is einav");
    CHECK(notebook.read(0,3, 0, Direction::Horizontal,19) == "hi my name is einav");
    //5
	notebook.write(1,0,0, Direction::Vertical, "hello world");
    CHECK(notebook.read(1,0, 0, Direction::Vertical,11) == "hello world");
    //6
    notebook.write(1, 1,0, Direction::Vertical, "my id is 12345678");
    CHECK(notebook.read(1,1, 0, Direction::Vertical,17) == "my id is 12345678");
    //7
    notebook.write(1,2,0, Direction::Vertical, "lalala");
    CHECK(notebook.read(1,2, 0, Direction::Vertical,6) == "lalala");
    //8
    notebook.erase(1,2, 0, Direction::Vertical,6);
    CHECK(notebook.read(1,2, 0, Direction::Vertical,6) == "~~~~~~");
    //9
    notebook.erase(0,0, 0, Direction::Horizontal,4);
    CHECK(notebook.read(0,0,0, Direction::Horizontal,4) == "~~~~");
    //10
    notebook.erase(0,1, 0, Direction::Vertical,5);
    CHECK(notebook.read(0,1, 0, Direction::Vertical,5) == "~~~~~");
    //11
    notebook.erase(0,2, 0, Direction::Horizontal,1);
    CHECK(notebook.read(0,2, 0, Direction::Horizontal,1) == "~");
    //12
    notebook.erase(1,0, 0, Direction::Vertical,11);
    CHECK(notebook.read(1,0, 0, Direction::Vertical,11) == "~~~~~~~~~~~");
    //13
    notebook.erase(0,3, 0, Direction::Horizontal,19);
    CHECK(notebook.read(0,3, 0, Direction::Horizontal,19) == "~~~~~~~~~~~~~~~~~~~");
}


TEST_CASE("Bad input") {
    ariel::Notebook notebook;
    //14
    notebook.write(1,1,0, Direction::Vertical, "hello");
    notebook.erase(1,1, 0, Direction::Vertical,5);
    CHECK_THROWS(notebook.write(1,1,0, Direction::Vertical, "byebye"));
    //15
    notebook.write(0,2,0, Direction::Vertical, "einav");
    CHECK_THROWS(notebook.write(0,2,0, Direction::Vertical, "hi"));
    //16
    notebook.write(0,1,0, Direction::Vertical, "lalala");
    notebook.erase(0,1, 0, Direction::Vertical,6);
    CHECK_THROWS(notebook.read(0,1, 0, Direction::Vertical,6));
    //17
    notebook.write(2,2,0, Direction::Vertical, "einav");
    CHECK_THROWS(notebook.write(0,2,0, Direction::Vertical, "hi"));
    //18
    CHECK_THROWS(notebook.write(-1,1,0, Direction::Vertical, "hello world"));
    //19
    CHECK_THROWS(notebook.write(1,-1,0, Direction::Vertical, "hello"));
    //20
    CHECK_THROWS(notebook.write(1,1,-2, Direction::Vertical, "hello world"));

}