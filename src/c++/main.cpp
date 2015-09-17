// main.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "FILE_LOG.h"

int send_message(std::string str_json_msg)
{
	int json_msg_len = str_json_msg.length();
	//std::cout<<json_msg_len; ´óÐ¡¶Ë
	std::cout<< char(((json_msg_len >> 0) & 0xFF))
		<< char(((json_msg_len >> 8) & 0xFF))
		<< char(((json_msg_len >> 16) & 0xFF))
		<< char(((json_msg_len >> 24) & 0xFF));

	FILE_LOG_FMT(file_log_name,"%s %d %s",__FILE__,__LINE__,"json_msg_len");
	FILE_LOG_FMT(file_log_name,"%s %d %d",__FILE__,__LINE__,json_msg_len);
	FILE_LOG_FMT(file_log_name,"%s %d %s",__FILE__,__LINE__,"str_json_msg");
	FILE_LOG_FMT(file_log_name,"%s %d str_json_msg = %s",__FILE__,__LINE__,str_json_msg.c_str());
	
	std::cout<<str_json_msg<<std::flush;

	return 0;
}


int main(int argc, char * argv[])
{
	std::string str_json_msg = "";
	unsigned int length = 0;

	str_json_msg = "{\"text\":\"messaging start\"}";

	send_message(str_json_msg);

    while (1){
		str_json_msg = "";
		length = 0;

        //read the first four bytes (=> Length)
        /*for (int i = 0; i < 4; i++)
        {
            int read_char = getchar();
            length += read_char * (int) pow(2.0, i*8);
            std::string s = std::to_string((long long)read_char) + "\n";
            fwrite(s.c_str(), sizeof(char), s.size(), f);
            fflush(f);
        }*/

        //Neat way!
        for (int i = 0; i < 4; i++)
        {
            unsigned int read_char = getchar();
            length = length | (read_char << i*8);
        }

        //read the json-message
        
        for (int i = 0; i < length; i++)
        {
            str_json_msg += getchar();
        }

        // Now we can output our message
		if (str_json_msg == "{\"text\":\"#STOP#\"}" || str_json_msg == "{\"text\":\"#EXIT#\"}" || str_json_msg == "{\"text\":\"#QUIT#\"}"){
            str_json_msg = "{\"text\":\"EXITING...\"}";

			send_message(str_json_msg);
            break;
        }

		send_message(str_json_msg);
    }

	str_json_msg = "{\"text\":\"messaging end\"}";

	send_message(str_json_msg);

    return 0;
}
