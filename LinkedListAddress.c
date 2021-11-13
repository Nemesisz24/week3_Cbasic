#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct add{
    char name[20];
    char email[50];
    int age;
} add;
typedef struct node{
    add data;
    struct node *next;
} node;
typedef struct addlist{
    node *phead;
    node *ptail;
} addlist;
void makelist(addlist *l){
    l->phead = l->ptail = NULL;
}
node* makenode(add x){
    node*p=(node*)malloc(sizeof(node));
    p->data = x;
    p->next= NULL;
    return p;
}
void themvaocuoi(addlist *l,node *p){
    if (l->phead == NULL){
        l->phead=l->ptail=p;
    } else{
        l->ptail->next=p;
        l->ptail=p;
    }
}
node *timkiem(addlist *l, char s[]){
    node *k;
    for (k=l->phead;k!=NULL;k=k->next){
        if (strcmp(k->data.name,s)==0)
            return k;
    } 
    return NULL;
}
int main(){
    int n,i;
    FILE *f=fopen("address.dat","w+b");
    FILE *f1=fopen("addressw.dat","wb");
    if (f==NULL){
        printf("Loi moi file!");
        return 0;
    }
    if (f1==NULL){
        printf("Loi moi file!");
        return 0;
    }
    add x;
    addlist l;
    makelist(&l);
    printf("Nhap so phan tu:");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Nhap data thu %d:\n",i+1);
        printf("Nhap ten:");
        fflush(stdin);
        gets(x.name);
        printf("Nhap email:");
        fflush(stdin);
        gets(x.email);
        printf("Nhap tuoi:");
        scanf("%d",&x.age);
        node *p=makenode(x);
        themvaocuoi(&l,p);
        fwrite(&x,sizeof(add),1,f);
    }
    fclose(f);
    FILE *f2=fopen("address.dat","rb");
    printf("Nhap email can tim:");
    char s[100];
    fflush(stdin);
    gets(s);
    while (!feof(f2)){
        add a;
        fread(&a,sizeof(add),1,f2);
        if (strcmp(a.email,s) == 0){
            printf("Name: %s\n",a.name);
            printf("Email: %s\n",a.email);
            printf("Age: %d\n",a.age);
            break;
        }
    }
    fclose(f2);
    fclose(f1);
    return 0;

}
