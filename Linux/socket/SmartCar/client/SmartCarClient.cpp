#include "SmartCarClient.h"
#include <iostream>
#include <string.h>
#include <string>
using namespace  std;

int main(){
    char *ip_addr= "192.168.1.100";
    int port_ctl = 8888;
    int port_cam = 2001;
    ControlCar CtlCar(ip_addr, port_ctl, port_cam);

    int ret = CtlCar.ControlConnectCtl();
    
	if(ret == -1){
        cout << "Error: Connect Seriral Server Failure" << endl;
		perror("Error");
        exit(0);
    }
    char choice;
    cout << "请输入w s a d 对小车进行控制" << endl;
    while(1){
        cin >> choice;
        switch(choice){
            case 'w': CtlCar.PressUpButton();
                      break;
            case 's': CtlCar.PressDownButton();
                      break;
            case 'a': CtlCar.PressLeftButton();
                      break;
            case 'd': CtlCar.PressRightButton();
                      break;
            default: cout<< " 未定义指令" << endl;
                     break;
        }
    }

    return 0;
}
