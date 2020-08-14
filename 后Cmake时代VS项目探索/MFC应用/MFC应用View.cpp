
// MFC应用View.cpp: CMFC应用View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC应用.h"
#endif

#include "MFC应用Doc.h"
#include "MFC应用View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC应用View

IMPLEMENT_DYNCREATE(CMFC应用View, CView)

BEGIN_MESSAGE_MAP(CMFC应用View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC应用View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC应用View 构造/析构

CMFC应用View::CMFC应用View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC应用View::~CMFC应用View()
{
}

BOOL CMFC应用View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC应用View 绘图

void CMFC应用View::OnDraw(CDC* /*pDC*/)
{
	CMFC应用Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC应用View 打印


void CMFC应用View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC应用View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC应用View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC应用View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFC应用View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC应用View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC应用View 诊断

#ifdef _DEBUG
void CMFC应用View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC应用View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC应用Doc* CMFC应用View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC应用Doc)));
	return (CMFC应用Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC应用View 消息处理程序
