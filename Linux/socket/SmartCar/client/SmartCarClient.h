#ifndef __SMART_CAR_CLIENT__
#define __SMART_CAR_CLIENT__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
using namespace std;

class ControlCar{
	
	private:
		int sockfd_ctl;
		int sockfd_cam;
		struct sockaddr_in addr_in_ctl;
		struct sockaddr_in addr_in_cam;
        int ip_port_ctl;
        int ip_port_cam;
        char ip_addr[20];

	public:
		ControlCar(char* ip, int port_ctl, int port_cam):ip_port_ctl(port_ctl),ip_port_cam(port_cam)
        {
            strcpy(ip_addr, ip);  
			
			// 初始化socket
            sockfd_ctl = socket(AF_INET, SOCK_STREAM, 0);
			sockfd_cam = socket(AF_INET, SOCK_STREAM, 0);
			
			// 初始化addr_in_ctl结构体
            memset((void*)&addr_in_ctl, 0x00, sizeof(addr_in_ctl));
            addr_in_ctl.sin_family = AF_INET;
            addr_in_ctl.sin_port = htons(ip_port_ctl);
            addr_in_ctl.sin_addr.s_addr = inet_addr(ip_addr);
			
			// 初始化addr_in_cam
			memset((void*)&addr_in_cam, 0x00, sizeof(addr_in_cam));
            addr_in_cam.sin_family = AF_INET;
            addr_in_cam.sin_port = htons(ip_port_ctl);
            addr_in_cam.sin_addr.s_addr = inet_addr(ip_addr);
		}

        // 连接串口服务器
        int ControlConnectCtl(){
            return connect(sockfd_ctl, (sockaddr*)&addr_in_ctl, sizeof(addr_in_ctl));
        }

        // 连接视频服务器
        int ControlConnectCam(){
        	return connect(sockfd_cam, (sockaddr*)&addr_in_cam, sizeof(addr_in_cam));
        }

        // 前
        void PressUpButton(){
            char up_buff[5] = {(char)0xff, 0, (char)0x01, 0,(char)0xff};
            char stop_buff[5] = {(char)0xff, 0, 0, (char)0, (char)0xff};
            ssize_t ret = send(sockfd_ctl, up_buff, sizeof(up_buff), 0);
            if(ret == -1){
				cout << "Send Message Failure" << endl;
            } else {
                sleep(1);
                ret = send(sockfd_ctl, stop_buff, sizeof(stop_buff), 0);
                if(ret == -1){ 
					cout << "Send Message Failure" << endl;
                }
            }
        }

        // 后
        void PressDownButton(){
            char up_buff[5] = {(char)0xff, 0, (char)0x02, 0 ,(char)0xff};
            char stop_buff[5] = {(char)0xff, 0,(char)0, 0, (char)0xff};
            ssize_t ret = send(sockfd_ctl, up_buff, sizeof(up_buff), 0);
            if(ret == -1){
                printf("Send Message Failure\n");
            }else{
                sleep(1);
                ret = send(sockfd_ctl, stop_buff, sizeof(stop_buff), 0);
                if(ret == -1){
                    printf("Send Message Failure\n");
                }
            }
        }
        
        // 左
        void PressLeftButton(){
            char up_buff[5] = {(char)0xff, 0, (char)0x03, 0,(char)0xff};
            char stop_buff[5] = {(char)0xff, 0, (char)0, 0, (char)0xff};

			for(int i = 0; i < 5; i++){
				printf("%d ", up_buff[i]);
			}
			printf("\n");
            ssize_t ret = send(sockfd_ctl, up_buff, sizeof(up_buff), 0);
            if(ret == -1){
                printf("Send Message Failure\n");
            }else{
                sleep(1);
                ret = send(sockfd_ctl, stop_buff, sizeof(stop_buff), 0);
                if(ret == -1){
                    printf("Send Message Failure\n");
                }
            }
        }

        // 右
        void PressRightButton(){
            
			char up_buff[5] = {(char)0xff, 0, (char)0x04, 0,(char)0xff};
            char stop_buff[5] = {(char)0xff, 0, (char)0, 0, (char)0xff};
			
			ssize_t ret = send(sockfd_ctl, up_buff, sizeof(up_buff), 0);
            
			if(ret == -1){
                printf("Send Message Failure\n");
            }else{
                sleep(1);
                ret = send(sockfd_ctl, stop_buff, sizeof(stop_buff), 0);
                if(ret == -1){
                    printf("Send Message Failure\n");
                }
            }
        }
           
        ~ControlCar(){
            close(sockfd_ctl);
            close(sockfd_cam);
        }
};

#endif //__SMART_CAR_CLIENT__
