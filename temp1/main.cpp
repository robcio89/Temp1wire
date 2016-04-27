#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

//const string temp_sensor = "/sys/bus/w1/devices/28-000004647259/w1_slave";
const string temp_sensor_rpi2 = "/sys/bus/w1/devices/28-000004647259/w1_slave";

std::vector<std::string> get_lines_from_file(const std::string& file)
{
	string line;
	ifstream myfile(file);
	std::vector<std::string> lines;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			lines.push_back(line);
		}
		myfile.close();
	}
	return lines;
}

float read_temp()
{
	auto lines = get_lines_from_file(temp_sensor_rpi2);
	
	auto pos = lines[1].find("t=");

	std::string temp_str = lines[1].substr(pos+2);

	return stof(temp_str) / 1000;
}

int main()
{
	cout << "Witam w programie do pomiaru temperatury!\n";

	for (int i = 0; i < 10; ++i)
	{
		auto temp_c = read_temp();
		cout << "Temp [C]: " <<  temp_c  << ", Temp [F] " << temp_c * 9.0 / 5.0 + 32 << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	return 0;
}