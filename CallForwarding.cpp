#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct fw_request
{
	string source;
	int begin;
	int duration;
	string destination;
	bool reached;
};

void CallForwarding(string s_time, string destination, vector<fw_request> requests)
{
	stringstream ss_time;
	ss_time << s_time;
	int time = 0;
	ss_time >> time;
	if (requests.empty())
	{
		cout << "AT " << s_time << " CALL TO " << destination << " RINGS " << destination <<endl;
		return;
	}
	string dest = destination;
	while (1)
	{
		bool is_fowarded = false;
		for (vector<fw_request>::iterator it=requests.begin(); it!=requests.end(); it++)
		{
			fw_request& request = *it;
			if (dest.compare(request.source) == 0 && time>=request.begin && time<=(request.begin+request.duration))
			{
				dest = request.destination;
				if (request.reached == true)
				{
					dest = "9999";
				}
				else
				{
					request.reached = true;
				}
				is_fowarded = true;
				break;
			}
		}
		if (is_fowarded == false)
		{
			break;
		}
	}
	cout << "AT " << s_time << " CALL TO " << destination << " RINGS " << dest <<endl;
}

int main()
{
	int sys_num = 0;
	cin >> sys_num;
	cout << "CALL FORWARDING OUTPUT" << endl;
	for (int i=0; i<sys_num; i++)
	{
		cout << "SYSTEM " << i+1 << endl;
		vector<fw_request> requests;
		string source;
		string destination;
		string s_begin;
		int begin = 0;
		int duration;
		cin >> source;
		while (source.compare("0000") != 0)
		{
			cin >> begin >> duration >> destination;
			fw_request request;
			request.source = source;
			request.begin  = begin;
			request.duration    = duration;
			request.destination = destination;
			request.reached = false;
			requests.push_back(request);
			cin >> source;
		}
		//cout << "calling" << endl;
		cin >> s_begin;
		while (s_begin.compare("9000") != 0)
		{
			cin >> destination;
			CallForwarding(s_begin, destination, requests);
			cin >> s_begin;
		}
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}