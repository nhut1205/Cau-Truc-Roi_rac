#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

typedef int ItemType;

#define VC 9			
#define MAXV 11			
#define MAXE 100
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
int Dijkstra(Graph g, int *&P, int s, int e);

void main()
{
	Graph G;
	read_Adjacent_Matrix_Data("input_mtk_01.txt", G);
	showGraph(G);

	printf("\n---------Thuat toan Dijkstra---------\n");
	int start, end;
	input_Start_End(G, start, end);
	int  *P;
	int len = Dijkstra(G, P, start, end);

	printf("\nDo dai ngan nhat cua duong di tu %d den %d la: %d\n", start, end, len);
	printf("Qua trinh duong di: ");
	int *Q = new int[G.n + 1];
	int i = end, k = 0;
	Q[0] = end;

	//Doi chieu xuat 
	while (i != start)
	{
		Q[++k] = P[i];
		i = P[i];
	}

	while (k >= 0)
	{
		printf(" --> ");
		printf("%d", Q[k]);
		k--;
	}
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

int Dijkstra(Graph g, int *&P, int s, int e)
{
	int a = s, b = e;
	// Len[i] - GTNT tu a -> i. Len1 danh dau do dai
	int *Len = new int[g.n + 1];
	int *S = new int[g.n + 1];	//Danh dau dinh thuoc danh sach dac biet
	P = new int[g.n + 1];	//truy vet

	fill(Len, Len + g.n + 1, VC); //Gan duong di ban dau = vong cung
	fill(P, P + g.n + 1, a);
	fill(S, S + g.n + 1, 0);	//Danh sach dac biet
	Len[a] = 0;
	int i = a;

	for (int k = 1; k <= g.n; k++)
	{
		//Tim do dai ngan nhat trong cac dinh
		for (i = 1; i <= g.n; i++)
			if (!S[i] && Len[i] != VC)
				break;
		for (int j = i + 1; j <= g.n; j++)
			if (!S[j] && Len[j] < Len[i])
				i = j;
		S[i] = 1;

		//Tinh do dai tu dinh dang xet toi cac dinh tiep
		for (int j = 1; j <= g.n; j++)
		{
			if (!S[j] && g.w[i][j])
			{
				if (Len[i] + g.w[i][j] < Len[j])
				{
					Len[j] = Len[i] + g.w[i][j];
					P[j] = i;	//truy vet
				}
			}
		}
	}
	return Len[b];
}