# Cpp-MySQL
# MySQL connection c++1.1
The plateform must be Visual Studio 2013,Debug,Win32
it just works on Visual Studio 2013,Debug,Win32.
Dear friends,if you want to use cpp in order to connect with MySQL,there is a demo for it.
However,it is important for cpp to know the plateform.
Not long ago,I tried to use VS2013 to compile libs which are
compiled on VS2008(the demo libs on https://dev.mysql.com/downloads/connector/cpp/)
it just worked for int,but while program read the type of std::string,it throwed memory leak error.
Then,I read https://dev.mysql.com/doc/connector-cpp/8.0/en/,and use 2 days to config the enviroment.
Just use Cmake/Make to compile the libs on other plateforms,if you want to use it on other plateforms.
If you try to change any config while using this libs on other plateforms,you will know what is horrible.
I use 'subst p' in cmd to share the libs.
the command in cmd is 'subst p: YOUR_DRIVER_PATH',such as 'subst p: d:\driver',you should care what your role in cmd,
the driver is giant,because it contains boost-1.68.
boost-1.68 is also complied by VS2013.
That's all.
