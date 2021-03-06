// UserButton.cpp : implementation file
//

#include "stdafx.h"
#include "UserButton.h"


// CUserButton

IMPLEMENT_DYNAMIC(CUserButton, CButton)

CUserButton::CUserButton()
: m_bDown(FALSE)
, m_nBtnID(0)
{
}

CUserButton::~CUserButton()
{
}

BEGIN_MESSAGE_MAP(CUserButton, CButton)
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEMOVE()
    ON_WM_KEYDOWN()
END_MESSAGE_MAP()



// CUserButton message handlers

void CUserButton::OnLButtonDown(UINT nFlags, CPoint point)
{
    CButton::OnLButtonDown(nFlags, point);
    m_bDown = TRUE;
}

void CUserButton::OnLButtonUp(UINT nFlags, CPoint point)
{
    CButton::OnLButtonUp(nFlags, point);
    m_bDown = FALSE;
}

void CUserButton::OnMouseMove(UINT nFlags, CPoint point)
{
    CButton::OnMouseMove(nFlags, point);
    if(m_bDown)
    {
        CWnd* pParent = GetParent();
        if(pParent)
            pParent->SendMessage(WM_USERBUTTON_DRAGGING, m_nBtnID, 0);
    }
}

void CUserButton::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{

    CButton::OnKeyDown(nChar, nRepCnt, nFlags);
}
