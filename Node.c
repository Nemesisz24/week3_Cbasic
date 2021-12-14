#include<stdio.h>
#define MAX 100
typedef struct Linkedlist{//Cau truc cua 1 node
    float data;
    struct Linkedlist *next;
} node;
node head,end,*cur;
node Cnode(float diem){//Tao node moi
    node temp;
    temp.data = diem;
    temp.next = NULL;
    return temp;
}
node Cnodehead(float diem){//Tao node moi vao dau danh sach
    node temp;
    temp=Cnode(diem);
    temp.next=&head;
    head=temp;
    return head;
}
node Cnodeend(float diem){//Tao node moi vao cuoi danh sach
    node temp;
    temp=Cnode(diem);
    temp.next=NULL;
    end.next=&temp;
    end=temp;
    return end;
}
node Cnodecur(float diem){//Tao node moi vao vi tri bat ki sau con tro current
    node temp;
    temp=Cnode(diem);
    temp.next= cur->next;
    cur->next=&temp;
    return temp;
}
int main(){
    float a;
   printf("Nhap diem so can them vao ds:");
   scanf("%f",&a);
   head.data=12;
   head.next=&end;
   end.data=1.2;
   end.next=NULL;
   float diem=9.3;
   Cnodehead(diem);
   diem=10.3;
   Cnodeend(diem);
   cur=&head;
   while (cur->next!=NULL){
       cur=cur->next;
       if(cur->data== 12){
           Cnodecur(a);
           printf("%f",Cnodecur(a).data);
       }
   }
   return 0;
}