#include "include.h"
#include "thread"
#include "mutex"

mutex s;
unique_lock<mutex> lock(s);

char sub1[56] = {	0xff, 0xff, 0x81, 0x00, 0x00, 0x00,
					0x00, 0x30, 0x00, 0x00, 0x00, 0x59, 0x01, 0x01, 0x02, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
					0x00, 0x10, 0x06, 0x00, 0x00, 0x10, 0x70, 0x02, 0x4e, 0x3f, 0x01, 0x00, 0x00, 0x1e, 0x00, 0x00,
					0x00, 0x0a, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x09, 0x04, 0x00, 0xac, 0x1f, 0x01, 0x0b, 0x00, 0x11,
					0x85, 0x56
};

char sub2[56] = { 0xff, 0xff, 0x81, 0x00, 0x00, 0x00,
					0x00, 0x30, 0x00, 0x00, 0x00, 0x59, 0x01, 0x01, 0x02, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
					0x00, 0x10, 0x06, 0x00, 0x00, 0x10, 0x50, 0x01, 0x4e, 0x2b, 0x01, 0x00, 0x00, 0x1e, 0x00, 0x00,
					0x00, 0x0a, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x09, 0x04, 0x00, 0xac, 0x1f, 0x01, 0x0b, 0x00, 0x11,
					0x85, 0x57
};

char sub3[56] = { 0xff, 0xff, 0x81, 0x00, 0x00, 0x00,
					0x00, 0x30, 0x00, 0x00, 0x00, 0x59, 0x01, 0x01, 0x02, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
					0x00, 0x10, 0x06, 0x00, 0x00, 0x10, 0x40, 0x02, 0x4e, 0x49, 0x01, 0x00, 0x00, 0x1e, 0x00, 0x00,
					0x00, 0x0a, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x09, 0x04, 0x00, 0xac, 0x1f, 0x01, 0x0b, 0x00, 0x11,
					0x85, 0x59
};

char sub4[56] = { 0xff, 0xff, 0x81, 0x00, 0x00, 0x00,
0x00, 0x30, 0x00, 0x00, 0x00, 0x59, 0x01, 0x01, 0x02, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x10, 0x06, 0x00, 0x00, 0x10, 0x80, 0x01, 0x4e, 0x99, 0x01, 0x00, 0x00, 0x1e, 0x00, 0x00,
0x00, 0x0a, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x09, 0x04, 0x00, 0xac, 0x1f, 0x01, 0x0b, 0x00, 0x11,
0x85, 0x5A
};



Dt_RECORD_MeObjects_E_x objects;

using namespace wsc::www;


int main()
{
	test A;

	
	WSADATA		wsa;                                   //指向WinSocket信息结构的指针
	SOCKET		SO_Client, SO_Server;
	SOCKADDR_IN Add_Local, Add_Local2, Add_Remote;

	origin = 1;

	char  RecvBuff[1500];			 //定义接收缓冲区

	//设置端口号
	int Local2Port = 30490;
	int ClientPort = 34134;    //0x8556

	Add_Local.sin_family = AF_INET;
	Add_Local.sin_port = htons(ClientPort);
	Add_Local.sin_addr.s_addr = htonl(INADDR_ANY); //htonl(INADDR_ANY);inet_addr("127.0.0.1")

	Add_Local2.sin_family = AF_INET;
	Add_Local2.sin_port = htons(Local2Port);
	Add_Local2.sin_addr.s_addr = htonl(INADDR_ANY); //htonl(INADDR_ANY);inet_addr("127.0.0.1")

	Add_Remote.sin_family = AF_INET;
	Add_Remote.sin_port = htons(Local2Port);
	Add_Remote.sin_addr.s_addr = inet_addr("172.31.1.50"); //htonl(INADDR_ANY);inet_addr("127.0.0.1")

	//启动Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		cout << "WSAStartup Error = " << WSAGetLastError() << endl;
		system("pause");
		return -1;
	}

	//创建socket

	SO_Client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (SO_Client == SOCKET_ERROR)
	{
		cout << "SO_Client socket Error = " << WSAGetLastError() << endl;
		system("pause");
		return -1;
	}

	SO_Server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (SO_Server == SOCKET_ERROR)
	{
		cout << "SO_Server socket Error = " << WSAGetLastError() << endl;
		system("pause");
		return -1;
	}


	//绑定本地地址到socket
	if (::bind(SO_Client, (SOCKADDR*)&Add_Local2, sizeof(Add_Local2)) == SOCKET_ERROR)
	{
		cout << "SO_Client bind Error = " << WSAGetLastError() << endl;
		system("pause");
		return -1;
	}

	if (::bind(SO_Server, (SOCKADDR*)&Add_Local, sizeof(Add_Local)) == SOCKET_ERROR)
	{
		cout << "SO_Server bind Error = " << WSAGetLastError() << endl;
		system("pause");
		return -1;
	}

	//发送数据


	if (sendto(SO_Client, sub1, 56, 0, (sockaddr *)&Add_Remote, sizeof(Add_Remote)) == SOCKET_ERROR)
	{
		cout << "SO_Clien1t1 sendto Error = " << WSAGetLastError() << endl;
		closesocket(SO_Client);
		WSACleanup();
		system("pause");
		return -1;
	}
// 	if (sendto(SO_Client, sub3, 56, 0, (sockaddr *)&Add_Remote, sizeof(Add_Remote)) == SOCKET_ERROR)
// 	{
// 		cout << "SO_Clien1t2 sendto Error = " << WSAGetLastError() << endl;
// 		closesocket(SO_Client);
// 		WSACleanup();
// 		system("pause");
// 		return -1;
// 	}
// 
// 	Sleep(5);
// 
// 	if (sendto(SO_Client, sub2, 56, 0, (sockaddr *)&Add_Remote, sizeof(Add_Remote)) == SOCKET_ERROR)
// 	{
// 		cout << "SO_Clien1t3 sendto Error = " << WSAGetLastError() << endl;
// 		closesocket(SO_Client);
// 		WSACleanup();
// 		system("pause");
// 		return -1;
// 	}
// 	if (sendto(SO_Client, sub4, 56, 0, (sockaddr *)&Add_Remote, sizeof(Add_Remote)) == SOCKET_ERROR)
// 	{
// 		cout << "SO_Clien1t4 sendto Error = " << WSAGetLastError() << endl;
// 		closesocket(SO_Client);
// 		WSACleanup();
// 		system("pause");
// 		return -1;
// 	}
	cout << "Message Send OK!" << endl;

	//接收数据
	int len = sizeof(Add_Local);
	while (true)
	{
		if (recvfrom(SO_Server, RecvBuff, sizeof(RecvBuff), 0, (sockaddr *)&Add_Local, &len) == SOCKET_ERROR)
		{
			cout << "SO_Server recv Error = " << WSAGetLastError() << endl;
			closesocket(SO_Server);
			WSACleanup();
			system("pause");
			return -1;
		}

		uint16 serviceID = RecvBuff[0] << 8 | RecvBuff[1];
		uint16 methodID  = RecvBuff[2] << 8 | RecvBuff[3];

// 		cout << "serviceID= " << hex << serviceID << endl;
// 		cout << "methodID= " << hex <<methodID << endl;

		if (serviceID == 0x7002 && methodID == 0xC026)
		{
			uint8 OBJ_Protocol_Version = RecvBuff[40];
			uint8 OBJ_Sync_ID = RecvBuff[41];
			memcpy(&objects, &RecvBuff[16], sizeof(objects));

// 			printf("RecvBuff[40] = %d\n", OBJ_Protocol_Version);
// 			printf("objects.stObjects_Header.OBJ_Protocol_Version = %d\n", (uint8)objects.stObjects_Header.OBJ_Protocol_Version);
// 			printf("RecvBuff[41] = %d\n", OBJ_Sync_ID);
// 			printf("objects.stObjects_Header.OBJ_Sync_ID = %d\n\n", (uint8)objects.stObjects_Header.OBJ_Sync_ID);


//			cout << "RecvBuff[40] = " << dec << (unsigned)OBJ_Protocol_Version << endl;
//			cout << "objects.stObjects_Header.OBJ_Protocol_Version = " << dec << (unsigned)objects.stObjects_Header.OBJ_Protocol_Version << endl;
//			cout << "RecvBuff[41] = " << dec << (unsigned)OBJ_Sync_ID << endl;
			cout << "objects.stObjects_Header.OBJ_Sync_ID = " << dec << (unsigned)objects.stObjects_Header.OBJ_Sync_ID << endl;
			cout << "objects.stHeader.Counter = " << dec << (unsigned)objects.stHeader.Counter << endl;
		}
	}


	closesocket(SO_Client);
	closesocket(SO_Server);
	WSACleanup();

	system("pause");
	return 1;

}


