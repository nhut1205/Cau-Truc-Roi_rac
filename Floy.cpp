#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stack>
using namespace std;

typedef int ItemType;

#define VC 9			
#define MAXV 11			
#define MAXE 20
#define TRUE 1
#define FALSE 0

struct Graph
{
	ItemType flat;              //lo?i d? th?: (0) - d? th? vô hu?ng; (1) - d? th? có hu?ng
	ItemType n;					//S? d?nh c?a d? th?
	ItemType w[MAXV][MAXV];
};

int visited[100];	//Danh dau cac dinh da duoc tham

void initGraph(Graph &g);
bool read_Adjacent_Matrix_Data(char filename[], Graph &g);
void showGraph(Graph g);
void input_Start_End(Graph g, int &start, int &end);
int Floy(Graph g, int P[][MAXV], int s, int e);
void truyVet(Graph g, int P[][MAXV], int s, int e);

void main()
{
	Graph G;
	int start, end;
	int  P[MAXV][MAXV];
	initGraph(G);
	read_Adjacent_Matrix_Data("input_mtk_01.txt", G);
	showGraph(G);

	printf("\n---------Thuat toan FLOY---------\n");
	input_Start_End(G, start, end);
	int len = Floy(G, P, start, end);

	printf("\nDo dai ngan nhat cua duong di tu %d den %d la: %d\n", start, end, len);
	printf("Qua trinh duong di: ");
	truyVet(G, P, start, end);
	_getch();
}

void initGraph(Graph &g)
{
	g.flat = -1;
	g.n = 0;
	for (int i = 0; i <= MAXV; i++)
	for (int j = 0; j <= MAXV; j++)
		g.w[i][j] = VC;
}

bool read_Adjacent_Matrix_Data(char filename[], Graph &g)
{
	initGraph(g);
	FILE* fi = fopen(filename, "rt");
	if (!fi)
	{
		printf("\nLOI DOC FILE\n\n");
		return false;
	}
	fscanf(fi, "%d", &g.flat);			//lo?i d? th?
	fscanf(fi, "%d", &g.n);				//s? d?nh
	for (int i = 1; i <= g.n; i++)
	for (int j = 1; j <= g.n; j++)
		fscanf(fi, "%d", &g.w[i][j]);
	fclose(fi);
	return true;
}

void showGraph(Graph g)
{
	if (g.flat == -1)
	{
		printf("\nKHONG PHAI DO THI!!!\n\n");
	}
	printf("\nSo dinh: %d", g.n);
	if (g.flat == 0)
		printf("\nDO THI VO HUONG\n\n");
	else printf("\nDO THI CO HUONG\n\n");
	printf("\nDANH SACH CANH:\n");
	printf("     ");
	for (int i = 1; i <= g.n; i++)
		printf("%5d", i + 1);
	printf("\n");
	for (int i = 1; i <= g.n; i++)
	{
		printf("%5d", i + 1);
		for (int j = 1; j <= g.n; j++)
			printf("%5d", g.w[i][j]);
		printf("\n");
	}
	printf("\n");
}

void input_Start_End(Graph g, int &start, int &end)
{
	int a, b;
	a = b = 0;
	printf("Cac dinh danh so tu 1 den %d.\n", g.n);
	do
	{
		printf("Nhap dinh bat dau: ");
		scanf("%d", &a);
		if (a < 1 || a > g.n)
			printf("Khong hop le! \nNhap lai dinh bat dau (1 <= a <= %d): ", g.n);
	} while (a < 1 || a > g.n);

	do
	{
		printf("Nhap dinh ket thuc: ");
		scanf("%d", &b);
		if (b < 1 || b > g.n)
			printf("Khong hop le! \nNhap lai dinh ket thuc (1 <= b <= %d): ", g.n);
	} while (b < 1 || b > g.n);
	start = a;
	end = b;
}

int Floy(Graph g, int P[][MAXV], int s, int e)
 {
	int a = s, b = e;
	int A[MAXV][MAXV];

	for (int i = 1; i <= g.n; i++)
	{
		for (int j = 1; j <= g.n; j++)
		{
			if (g.w[i][j])
				A[i][j] = g.w[i][j];
			else
				A[i][j] = VC;
			P[i][j] = -1;
		}
	}

 	for (int k = 1; k <= g.n; k++)
	{
		for (int i = 1; i <= g.n; i++)
		{
			for (int j = 1; j <= g.n; j++)
			{
				if (A[i][j] > A[i][k] + A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j];
					P[i][j] = k;
				}
			}
		}
	}
	return A[a][b];
}

//void truyVet(Graph g, int P[][MAXV], int s, int e)
//{
//	stack <int> S1;
//	stack <int> S2;
//	S1.push(s); // danh sach nap cac dinh vao
//	S2.push(e); // danh sach nap cac dinh ra
//	int dich, tg;
//	while (!S1.empty())
//	{
//		dich = S1.top(); // dich = phan tu dau tien
//		S1.pop(); // dua phan tu do ra
//		S2.push(dich); // cho vao danh sach xuat
//		if (!S1.empty()) // trong khi s1 khong rong thi tiep tuc tim cac dich
//		{
//			tg = S1.top();
//			while (P[tg][dich] != -1) // tim cac dinh di tu tg den dich
//			{
//				S1.push(P[tg][dich]);
//				tg = S1.top();
//			}
//		}
//	}
//
//	printf("%d", S2.top());
//	S2.pop();
//
//	while (!S2.empty())
//	{
//		printf(" --> %d", S2.top());
//		S2.pop();
//	}
//}

void truyVet(Graph g, int P[][MAXV], int s, int e)
{
	//truy vet
	stack <int> S1, S2;
	S1.push(s);		//danh sach nap cac dinh vao
	S1.push(e);		//danh sach xuat cac dinh ra
	int dinh, tg;
	while (!S1.empty())
	{
		dinh = S1.top();	//dinh = phan tu dau tien
		S1.pop();			//Du phan tu do ra
		S2.push(dinh);		//cho vao danh sach xuat
		if (!S1.empty())	//trong khi S1 khong rong thi tiep tu tim cac dinh
		{
			tg = S1.top();
			while (P[tg][dinh] != -1)	//tim cac diinh di tu tg den dinh
			{
				S1.push(P[tg][dinh]);
				tg = S1.top();
			}
		}
	}

	printf("%d", S2.top());
	S2.pop();

	while (!S2.empty())
	{
		printf(" --> %d ", S2.top());
		S2.pop();
	}
}