#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>

void clrscr() // Ham clear man hinh
{
    system("@cls||clear");
}

typedef struct 
{
    char name[256]; // bien so
    int year;       // nam san xuat
    char brand[256]; // nhan hieu cua xe
    int m,n;      // toa do hang, cot cua xe
    int nhap;
} xe;
xe car[100];

int chiso[100];   // chỉ số số xe trong một cột

typedef struct node   // khai bao mot cai
{
    xe data;
    struct node *pNEXT;
} node;
node* top[100];

node* makeNode(char x)
{
    node* p = (node *) malloc (sizeof(node));
    //p->data = x;
    p->pNEXT = NULL;
    return p;
}

void push(char x, int i)
{
    node* p = makeNode(x);
    p->pNEXT = top[i];
    top[i] = p;
    chiso[i]++;
    free(p);
}

void initStack(int i)
{
    top[i] = NULL;
}

// int Empty(int i)
// {
//     if (top[i]->data == 0)     // neu danh sach rong  
//         return 1;
//     return 0;
// }

void NhapXe(int i, int N)
{   
    for (int n = 0; n < N; n++)
    {
        if (car[n].nhap == 0)
        {   
            car[n].m = chiso[i], car[n].n = i;    // gắn tọa độ cho xe muốn đỗ
            car[n].nhap = 1;   // đánh dấu là đã từng nhập rồi để không nhập lại
            printf("Nhap vao xe muon do:\n");
            printf("Bien so:");
            fflush(stdin);
            gets(car[n].name);
            printf("Nam san xuat:");
            scanf("%d", &car[n].year);
            printf("Nhan hieu xe:");
            fflush(stdin);
            gets(car[n].brand);
            system("pause");
            break;
        }
    }
}

int findcar(int N)
{   
    char tencar[30];

    fflush(stdin);
    gets(tencar);
    for (int i = 0; i < N; i++)
    {
        if(strcasecmp(car[i].name, tencar) == 0)
        {
            printf("\n");
            printf("Day la xe ban dang tim kiem:\n");
            printf("Cot %d hang %d.\n", car[i].n + 1, car[i].m);
            printf("Bien so: %s\n", car[i].name);
            printf("Nam san xuat: %d\n", car[i].year);
            printf("Hang xe: %s\n", car[i].brand);
            return 1;
        }
    }
    printf("Xe ban tim kiem khong co trong bai do.\nMoi ban quay lai.\n");
}

int deleteCar(int N, int C)
{   
    char tencar[30];

    fflush(stdin);
    gets(tencar);
    for (int i = 0; i < C; i++)     // duyệt từng cột 
    {
        for (node *k = top[i]; k != NULL; k = k->pNEXT)
        {   
            printf("anh yeu em fake\n");
            if(strcasecmp((top[i]->data).name, tencar) == 0)
                printf("anh yeu em\n");
        }
    }
    printf("Xe ban tim kiem khong co trong bai do.\nMoi ban quay lai.\n");
}


void XuatDanhSach(int H, int C)
{   
    for (int i = 0; i < H; i++)    // theo hang
    {
        for (int k = 0; k < C; k++)  // theo cot
        {   
            if (chiso[k] >=  i + 1 )
            {
                printf("X");
            }
            else
                printf("_");        
        }
        printf("\n");
    }    
}

int main()
{
    int so, N, C, H;  // N là số ô đỗ, C là số cột 
    do 
    {   
        clrscr();
        printf("1:Nhap so hang va cot.\n");
        printf("2:Nhap xe.\n");
        printf("3:Tim kiem xe.\n");
        printf("4:Xoa xe.\n");
        printf("5:Thoat chuong trinh.\n");
        printf("Hay chon cac options tu 1-5: \n");
        printf("NHO SUA HAM FREE(P) TRUOC KHI CHAY LAI.!!!!!!!!!");
        scanf("%d", &so);
    
        switch(so)
        {
            case 1:
            do
            {
                printf("Hay nhap so luong o do N:\n"); 
                scanf("%d", &N);
                if(N <= 0 || N >= 100)
                {
                    printf("Ban da nhap sai yeu cau nhap lai.\n");
                }
            } while (N <= 0 || N >= 100); 
            do
            {
                printf("Hay nhap so luong cot C:\n"); 
                scanf("%d", &C);
                if(C <= 0 || C > N )
                {
                    printf("Ban da nhap sai yeu cau nhap lai.\n");
                }
            } while (C <= 0 || C > N); 
            H = N/C;
            for (int i = 0; i < H ; i++)    //khoi tao vi tri trong cho top
            {
                initStack(i);
                chiso[i]=0;
            }
            for (int i = 0; i < N; i++)   // khoi tao chi so nhap cho car
            {
                car[i].nhap = 0; 
            }
            
            printf("\tSo o do     So hang dau xe      So cot\n");
            printf("\t%-12d%-20d%-6d\n", N, H, C);
            system("pause");
            break;
        
            case 2:
            for (int i = 0; i < C ; i++)
            {   
                if (chiso[i] == H)    // cot nay da day
                {   
                    printf("Cot %d da het cho trong. Moi ban do xe sang cot ban canh.\n", i + 1);
                    if (i == C - 1 )
                    {
                        printf("Da het cho trong. Moi quy khach quay lai sau.\n");
                        break;
                    }
                    continue;
                }          
                push(1, i);  // tuc la vi tri nay con trong
                printf("Vi tri cot %d hang %d con trong moi ban do xe vao.\n", i + 1, chiso[i]);
                NhapXe(i, N);
                break;           
            }
            printf("Hinh anh bai do xe:\n");
            XuatDanhSach(H,C);        
            system("pause");
            break;
            
            case 3: 
            printf("Hay nhap ten xe ma ban muon tim kiem:\n");
            findcar(N);
            system("pause");
            break;

            case 4:
            printf("Hinh anh bai do xe:\n");
            XuatDanhSach(H,C); 
            printf("Hay nhap ten xe ma ban muon di chuyen:\n");
            deleteCar(N,C);
            system("pause");
            break;

            case 5: 
            
            break;

        }
    }
    while (so != 5);
    
    return 0;
}