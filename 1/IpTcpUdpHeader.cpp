#include<stdio.h>
#include<malloc.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -2


typedef struct udp_hdr              //UDPͷ�� 
{
            unsigned short sourceport;
            unsigned short destport;
            unsigned short totallength;
            unsigned short checksum;
}UDP;

typedef struct ip_hdr {                //IPͷ�� 
	         unsigned char ver_hl;		//�汾�ź�ͷ������
	         unsigned char tos;			//��������
	         unsigned short totallength;	//�ܳ���
	         unsigned short ident;		//16λ��ʶ
	         unsigned short frag_and_flags;	//��־λ
	         unsigned char ttl;		//����ʱ��TTL
	         unsigned char proto;	//Э��
	         unsigned short checksum;	//IP�ײ�У���
	         unsigned int sourceIP;	//ԴIP
	         unsigned int destIP;	//Ŀ��IP
}IP;

typedef struct tcp_hdr {			//TCP����ͷ�� 
	         unsigned short sourceport;	//Դ�˿�
	         unsigned short destport;		//Ŀ�Ķ˿�
	         unsigned int seq;			//���
	         unsigned int ack;			//ȷ�Ϻ�
	         unsigned char hlen;        //�ײ����Ⱥ�4λ�ı����ֶ� 
	         unsigned char control;     //2λ�����ֶκ�6λ�����ֶ� 
	         unsigned short win;		//���ڴ�С
	         unsigned short checksum;		//У���
	         unsigned short urp;		//����ָ��
}TCP;


main()                      
{
      unsigned char buff1[100]={0x45,0x00,0x05,0xdc,
                                0x00,0x14,0x20,0x00,
                                0x80,0x06,0x72,0xb7,
                                0xc0,0xa8,0x0b,0x02,
                                0xc0,0xa8,0x16,0x03,
                                0xcb,0x84,0x00,0x0d,
                                0x00,0x1c,0x00,0x1c};//UDP
      unsigned char buff2[100]={0x45,0x00,0x05,0xdc,
                                0x00,0x14,0x20,0x00,
                                0x80,0x06,0x72,0xb7,
                                0xc0,0xa8,0x0b,0x02,
                                0xc0,0xa8,0x16,0x03,
                                0x00,0x50,0x07,0x45,
                                0x9b,0xd6,0x43,0x3c,
                                0x47,0xfd,0x37,0x50,
                                0x50,0x18,0xff,0x1f,
                                0x05,0xa5,0x00,0x00};//TCP
      IP *ip;UDP *udp;TCP *tcp;
      ip=(IP *)buff1;udp=(UDP *)(buff1+20);tcp=(TCP *)(buff2+20);
      
      
      printf("the version of datagram is: %u\n",(*ip).ver_hl>>4);
      printf("the length of datagram's ip header is: %u bytes\n",(((*ip).ver_hl)&15)*4);
 //     printf("the sourceport of datagram is: %u\n",(*udp).sourceport);
       printf("the sourceport of datagram is: %u\n",(*udp).sourceport);                 //�ֽڴ洢������ 
       while(1);
      

}

         

