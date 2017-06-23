//
// OS

#include "CookbookSampleFramework.h"

namespace VKCookbook {

#ifdef VK_USE_PLATFORM_WIN32_KHR

  namespace {
    enum UserMessage {
      USER_MESSAGE_RESIZE = WM_USER + 1,
      USER_MESSAGE_QUIT,
      USER_MESSAGE_MOUSE_CLICK,
      USER_MESSAGE_MOUSE_MOVE,
      USER_MESSAGE_MOUSE_WHEEL
    };
  }

  LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam ) {
    switch( message ) {
    case WM_LBUTTONDOWN:
      PostMessage( hWnd, USER_MESSAGE_MOUSE_CLICK, 0, 1 );
      break;
    case WM_LBUTTONUP:
      PostMessage( hWnd, USER_MESSAGE_MOUSE_CLICK, 0, 0 );
      break;
    case WM_RBUTTONDOWN:
      PostMessage( hWnd, USER_MESSAGE_MOUSE_CLICK, 1, 1 );
      break;
    case WM_RBUTTONUP:
      PostMessage( hWnd, USER_MESSAGE_MOUSE_CLICK, 1, 0 );
      break;
    case WM_MOUSEMOVE:
      PostMessage( hWnd, USER_MESSAGE_MOUSE_MOVE, LOWORD( lParam ), HIWORD( lParam ) );
      break;
    case WM_MOUSEWHEEL:
      PostMessage( hWnd, USER_MESSAGE_MOUSE_WHEEL, HIWORD( wParam ), 0 );
      break;
    case WM_SIZE:
    case WM_EXITSIZEMOVE:
      PostMessage( hWnd, USER_MESSAGE_RESIZE, wParam, lParam );
      break;
    case WM_KEYDOWN:
      if( VK_ESCAPE == wParam ) {
        PostMessage( hWnd, USER_MESSAGE_QUIT, wParam, lParam );
      }
      break;
    case WM_CLOSE:
      PostMessage( hWnd, USER_MESSAGE_QUIT, wParam, lParam );
      break;
    default:
      return DefWindowProc( hWnd, message, wParam, lParam );
    }
    return 0;
  }

  WindowFramework::WindowFramework( const char               * window_title,
                                    int                        x,
                                    int                        y,
                                    int                        width,
                                    int                        height,
                                    VulkanCookbookSampleBase & sample ) :
    WindowParameters(),
    Sample( sample ),
    Created( false ) {
    WindowParameters.HInstance = GetModuleHandle( nullptr );

    WNDCLASSEX window_class = {
      sizeof( WNDCLASSEX ),             // UINT         cbSize
                                        /* Win 3.x */
      CS_HREDRAW | CS_VREDRAW,          // UINT         style
      WindowProcedure,                  // WNDPROC      lpfnWndProc
      0,                                // int          cbClsExtra
      0,                                // int          cbWndExtra
      WindowParameters.HInstance,       // HINSTANCE    hInstance
      nullptr,                          // HICON        hIcon
      LoadCursor( nullptr, IDC_ARROW ), // HCURSOR      hCursor
      (HBRUSH)(COLOR_WINDOW + 1),       // HBRUSH       hbrBackground
      nullptr,                          // LPCSTR       lpszMenuName
      "VulkanCookbook",                 // LPCSTR       lpszClassName
                                        /* Win 4.0 */
      nullptr                           // HICON        hIconSm
    };

    if( !RegisterClassEx( &window_class ) ) {
      return;
    }

    WindowParameters.HWnd = CreateWindow( "VulkanCookbook", window_title, WS_OVERLAPPEDWINDOW, x, y, width, height, nullptr, nullptr, WindowParameters.HInstance, nullptr );
    if( !WindowParameters.HWnd ) {
      return;
    }

    Created = true;
  }

  WindowFramework::~WindowFramework() {
    if( WindowParameters.HWnd ) {
      DestroyWindow( WindowParameters.HWnd );
    }

    if( WindowParameters.HInstance ) {
      UnregisterClass( "VulkanCookbook", WindowParameters.HInstance );
    }
  }

  void WindowFramework::Render() {
    if( Created &&
        Sample.Initialize( WindowParameters ) ) {

      ShowWindow( WindowParameters.HWnd, SW_SHOWNORMAL );
      UpdateWindow( WindowParameters.HWnd );

      MSG message;
      bool loop = true;

      while( loop ) {
        if( PeekMessage( &message, NULL, 0, 0, PM_REMOVE ) ) {
          switch( message.message ) {
          case USER_MESSAGE_MOUSE_CLICK:
            Sample.MouseClick( static_cast<size_t>(message.wParam), message.lParam > 0 );
            break;
          case USER_MESSAGE_MOUSE_MOVE:
            Sample.MouseMove( static_cast<int>(message.wParam), static_cast<int>(message.lParam) );
            break;
          case USER_MESSAGE_MOUSE_WHEEL:
            Sample.MouseWheel( static_cast<short>(message.wParam) * 0.002f );
            break;
          case USER_MESSAGE_RESIZE:
            if( !Sample.Resize() ) {
              loop = false;
            }
            break;
          case USER_MESSAGE_QUIT:
            loop = false;
            break;
          }
          TranslateMessage( &message );
          DispatchMessage( &message );
        } else {
          if( Sample.IsReady() ) {
            Sample.UpdateTime();
            Sample.Draw();
            Sample.MouseReset();
          }
        }
      }
    }

    Sample.Deinitialize();
  }

#endif

} // namespace VulkanCookbook
