# Cpp-MySQL
# MySQL connection c++1.1
<p>The plateform must be Visual Studio 2013,Debug,Win32</p>
<p>it just works on Visual Studio 2013,Debug,Win32.</p>
<p>Dear friends,if you want to use cpp in order to connect with MySQL,there is a demo for it.</p>
<p>However,it is important for cpp to know the plateform.</p>
<p>Not long ago,I tried to use VS2013 to compile libs which are
compiled on VS2008(the demo libs on https://dev.mysql.com/downloads/connector/cpp/)</p>
<p>it just worked for int,but while program read the type of std::string,it throwed memory leak error.</p>
<p>Then,I read https://dev.mysql.com/doc/connector-cpp/8.0/en/,and use 2 days to config the enviroment.</p>
<p>Just use Cmake/Make to compile the libs on other plateforms,if you want to use it on other plateforms.</p>
<p>If you try to change any config while using this libs on other plateforms,you will know what is horrible.</p>
<p>I use 'subst p' in cmd to share the libs.</p>
<p>The command in cmd is 'subst p: YOUR_DRIVER_PATH',such as 'subst p: d:\driver',you should care what your role in cmd,
the driver is giant,because it contains boost-1.68.</p>
<p>Boost-1.68 is also complied by VS2013.<p>
<p>That's all.<p>
