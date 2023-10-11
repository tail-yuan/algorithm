#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 20


typedef struct 
{
    char dept[20];
    char business[20];//业务
    char client[20];//客户
    int bh;//编号
}ST;

typedef struct SQueue
{
	ST data[SIZE];//数据
	int rear;//尾节点
	int length;//长度
	int size;//大小
}QE , *Queue;

int initQueue(Queue Q)
{//初始化
	Q->rear = -1;
	Q->length= 0;
	Q->size = SIZE;
	return 1;
}

int QueueEmpty(Queue Q)
{//队列空
	if(Q->length == 0)return 1;
	else return 0;
}

int QueueLength(Queue Q)
{//取得队列长
	return Q->length;
}

int QueueGetHead(Queue Q,ST *e)
{//取得队列头
	if(QueueEmpty(Q)){
		return 0;
	}
	int front = (Q->rear - Q->length +Q->size +1)% Q->size;
	* e = Q->data[front];
	return 1;
}

int QueueEnter(Queue Q, ST e)
{//进队列
	if(Q->length == Q->size)return 0;
	Q->length++;
	Q->rear = (Q->rear+1) % Q->size;
	Q->data[Q->rear] = e;
	return 1;
}

int QueueOut(Queue Q,ST *e)
{//出队列
	if(Q->length == 0)return 0;
	int front = (Q->rear - Q->length +Q->size +1)% Q->size;
	* e = Q->data[front];
	Q->length--;
	return 1;
}

void QueueTravers(Queue Q)
{//遍历队列
	int i = (Q->rear - Q->length +Q->size +1)% Q->size;
	for(; i < Q->length;i++)
	{
		printf("%s %s %d\n",Q->data[i].business,Q->data[i].client,Q->data[i].bh);
	}
		printf("%s %s %d\n",Q->data[i].business,Q->data[i].client,Q->data[i].bh);

}
int menu(){
    int s;
	printf("联通营业厅取号程序\n");
    printf("1. 排号服务\n");
    printf("2. 一号窗口叫号\n");
    printf("3. 二号窗口叫号\n");
	printf("4. 三号窗口叫号\n");
    printf("5. 显示信息\n");
    printf("0. 退出\n");
    printf("输入选择：\n");
    scanf("%d",&s);
    if(s>=0 && s<=5){
        return s;
    }
    else{
        printf("输入有误，重新输入! \n");
        scanf("%d",&s);
    }
}

int main(){
    ST d;
    int n1 = 0;
    int n2 = 0;
	int n3 = 0;
    int num;
    QE Q1,Q2,Q3;
    
    initQueue(&Q1);//创建队列1
    initQueue(&Q2);//创建队列2
	initQueue(&Q3);//创建队列3
    while (1)
    {

        num = menu();
		system("pause");
		system("cls");
        switch (num)
        {
        case 0:
			printf("欢迎下次使用\n");
			system("pause");
            return 0;
        case 1:
            printf("请输入选择的业务:手机业务/宽带业务 客户姓名\n");
            scanf("%s %s",d.business,d.client);
            if(strcmp(d.business,"手机业务")==0){
				if(n1<=n3)
				{
					d.bh = ++n1;
					QueueEnter(&Q1,d);
					printf("请去一号窗口排队\n");
				}
				else
				{
					d.bh = ++n3;
					QueueEnter(&Q3,d);
					printf("请去三号窗口排队\n");
				}
            }
            if(strcmp(d.business,"宽带业务")==0){
				if(n2<=n3)
				{
					d.bh = ++n2;
					QueueEnter(&Q2,d);
					printf("请去二号窗口排队\n");
				}
				else
				{
					d.bh = ++n3;
					QueueEnter(&Q3,d);
					printf("请去三号窗口排队\n");
				}
            }
            printf("完成\n");
			system("pause");
			system("cls");
            break;
        case 2:
            if(QueueOut(&Q1,&d)){
    	    	printf("请客户%s去窗口1办理手机业务\n",d.client);
				n1--;
			}
			else{
				printf("无人排队需要办理业务\n");
			} 
			system("pause");
			system("cls");
            break;
        case 3:
            if(QueueOut(&Q2,&d)){
    	    	printf("请客户%s去窗口2办理宽带业务\n",d.client);
				n2--;
			}
			else{
				printf("无人排队需要办理业务\n");
			} 
			system("pause");
			system("cls");
            break;
		case 4:
			 if(QueueOut(&Q3,&d)){
    	    	printf("请客户%s去窗口3办理%8s\n",d.client,d.business );
				n3--;
			}
			else{
				printf("无人排队需要办理业务\n");
			} 
			system("pause");
			system("cls");
            break;
        case 5:
            if(QueueGetHead(&Q1,&d)){
				printf("***************************************************\n");
				printf("     即将在窗口1办理手机业务的是客户%8s\n",d.client);
				printf("     目前窗口1还有%d人等候办理手机业务\n",QueueLength(&Q1)-1);	
				printf("***************************************************\n");
			}
			else{
				printf("***************************************************\n");
				printf("     窗口1无人排队\n");
				printf("***************************************************\n");				
			}
            if(QueueGetHead(&Q2,&d)){
				printf("     即将在窗口2办理宽带业务的是客户%8s\n",d.client);
				printf("     目前窗口2还有%d人等候办理宽带业务\n",QueueLength(&Q2)-1);	
				printf("***************************************************\n");
			}
			else{
				printf("     窗口2无人排队\n");
				printf("***************************************************\n");
			}
			if(QueueGetHead(&Q3,&d)){
				printf("     即将在窗口3办理%8s的是客户%8s\n",d.business ,d.client);
				printf("     目前窗口3还有%d人等候办理%8s\n",QueueLength(&Q3)-1,d.business );	
				printf("***************************************************\n");
			}
			else{
				printf("     窗口3无人排队\n");
				printf("***************************************************\n");
			}
			system("pause");
			system("cls");
            break;
        }

    }
}
