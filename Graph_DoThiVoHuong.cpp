/*
Họ và tên : Phạm Minh Nhựt
Lớp       : 12DHTH11
Buổi      : 1 
Tiết      : 1 - 5
*/
#include <stdio.h>
#include <conio.h>
#define VC 100 // Gía trị vô cực 
#define MaxV 20 //Số đỉnh tối đa
struct Graph
{
	int flag;
	int n;
	int m[MaxV][MaxV];
};
//==================================================================================================
void initGraph(Graph &g);
void showGraph(Graph g);
bool DOC_MA_TRAN_KE(char fileName[], Graph &g);
bool DOC_DANH_SACH_CANH(char fileName[], Graph &g);
bool DOC_DANH_SACH_KE(char fileName[], Graph &g);
//==================================================================================================
void menu()
{
	printf("-------------------------------\n");
	printf("|1.Hien thi ma tran ke         |\n");
	printf("|2.Hien thi danh sach canh     |\n");
	printf("|3.Hien thi canh ke            |\n"); 
	printf("-------------------------------\n");
}
void main()
{
	Graph G1 , G2 , G3;
	int luachon;
	do
	{
		menu();
		printf("Nhap lua chon cua ban : "); 
			scanf("%d", &luachon);
			switch (luachon)
			{
			case 1:
				if (DOC_MA_TRAN_KE("input_mtk.txt", G1))
					showGraph(G1);
				else
					printf("\nKhong the show graph");
				break;
			case 2:
				if (DOC_DANH_SACH_CANH("input_dsc.txt", G2))
					showGraph(G2);
				else
					printf("\nKhong the show graph");
				break;
			case 3:
				if (DOC_DANH_SACH_KE("input_dsk.txt", G3))
					showGraph(G3);
				else
					printf("\nKhong the show graph");
			}
	} while (luachon != 0);
	getch();
	
}
//==================================================================================================
void initGraph(Graph &g)
{
	g.flag = 0;
	g.n = 0;
	for (int i = 0; i < MaxV; i++)
	{
		for (int j = 0; j < MaxV; j++)
			g.m[i][j] = VC;
	}
}
//==================================================================================================
void showGraph(Graph g)
{
	if (g.flag == 0)
		printf("\n             DO THI VO HUONG\n");
	else
		printf("\nDO THI CO HUONG\n");
	printf("     ");
	for (int i = 0; i < g.n; i++)
		printf("%5d", i + 1);
	printf("\n");
	for (int i = 0; i < g.n; i++)
	{
		printf("%5d", i + 1);
		for (int j = 0; j < g.n; j++)
			printf("%5d", g.m[i][j]);
		printf("\n");
	}
}
//==================================================================================================
bool DOC_MA_TRAN_KE(char fileName[], Graph &g)
{
	initGraph(g);
	FILE *fi = fopen(fileName, "rt");
	if (fi == NULL)
	{
		printf("Loi khong the mo file");
		getch();
		return false;
	}
	fscanf(fi, "%d", &g.flag);
	// 0 đồ thị vô hướng
	// 1 đồ thị có hướng
	fscanf(fi, "%d", &g.n);
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
			fscanf(fi,"%d", &g.m[i][j]);
	}
	fclose(fi);
	return true;
}
//==================================================================================================
bool DOC_DANH_SACH_CANH(char fileName[], Graph &g)
{
	initGraph(g);
	FILE *fi = fopen(fileName, "rt");
	if (fi == NULL)
	{
		printf("Loi khong the mo file");
		getch();
		return false;
	}
	int soCanh, ddau, dcuoi;
	fscanf(fi, "%d", &g.flag);
	// 0 đồ thị vô hướng
	// 1 đồ thị có hướng
	fscanf(fi, "%d", &g.n);
	fscanf(fi, "%d", &soCanh);
	for (int i = 0; i < soCanh; i++)
	{
		fscanf(fi, "%d%d", &ddau, &dcuoi);
		g.m[ddau][dcuoi] = 1;
		if (g.flag == 0)
		{
			g.m[dcuoi][ddau] = 1;
		}
	}
	fclose(fi);
	return true;
}
//==================================================================================================
bool DOC_DANH_SACH_KE(char fileName[], Graph &g)
{
	initGraph(g);
	FILE *fi = fopen(fileName, "rt");
	if (fi == NULL)
	{
		printf("Loi khong the mo file");
		getch();
		return false;
	}
	int soTPLT, ddau, dke;
	fscanf(fi, "%d", &g.flag); // Đọc loại đồ thị
	// 0 đồ thị vô hướng
	// 1 đồ thị có hướng
	fscanf(fi, "%d", &g.n); // đọc sổ đỉnh của đồ thị
	fscanf(fi, "%d", &soTPLT);
	for (int i = 0; i < soTPLT; i++)
	{
		fscanf(fi, "%d", &ddau);
		while (true)
		{
			char chEnd;
			fscanf(fi, "%c", &chEnd);//đọc đỉnh kề
			if (chEnd == 10) break;//10 là mã ascii của ký tự '\n'
			fscanf(fi, "%d", &dke);
			g.m[ddau][dke] = 1;
			if (g.flag == 0)
			{
				g.m[dke][ddau] = 1;
			}
			if (i == soTPLT - 1) break; // đọc đủ số thành phần liên thông
		}
	}
	fclose(fi);
	return true;
}