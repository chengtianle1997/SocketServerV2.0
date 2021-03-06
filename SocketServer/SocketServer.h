#pragma once
/*

ServerNet.h

服务端：建立Socket，声明自身的端口号和地址并绑定到Socket，使用Listen打开监听，

然后不断用Accept去查看是否有连接，如果有，捕获Socket，并通过Recv获取消息的内容，

通信完成后调用CloseSocket关闭这个对应Accept到的Socket，如果不再需要等待任何客户端连接，那么用CloseSocket关闭掉自身的Socket

*/





#include<stdio.h>

#include<windows.h>

#include "fstream"

using namespace std;



#pragma comment(lib, "Ws2_32.lib")

typedef struct {

	unsigned char SerialNumber[64];
	int Framecnt;
	float s[2048];
	float ay[2048];

}SocketPackage;



class ServerNet

{

private:

	SOCKET m_sock;



public:

	//  初始化服务器

	int ServerInit(const char* address, int port);



	// 更新数据

	void ServerRun(int portnum ,const char* Filepath);

};

