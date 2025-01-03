#include "Common/d3dApp.h"
#include <DirectXColors.h>

using namespace DirectX;

// DirectX 초기화 클래스 선언부
class InitDirect3DApp : public D3DApp {
public:
	InitDirect3DApp(HINSTANCE hInstance);
	~InitDirect3DApp();

	virtual bool Initialize()override;

private:
	virtual void OnResize()override;
	virtual void Update(const GameTimer& gt)override;
	virtual void Draw(const GameTimer& gt)override;
	
};

InitDirect3DApp::InitDirect3DApp(HINSTANCE hInstance) : D3DApp(hInstance) {
}

InitDirect3DApp::~InitDirect3DApp() {
}

bool InitDirect3DApp::Initialize() {
	if (!D3DApp::Initialize())
		return false;

	return true;
}

void InitDirect3DApp::OnResize() {
	D3DApp::OnResize();
}

void InitDirect3DApp::Update(const GameTimer& gt) {

}

void InitDirect3DApp::Draw(const GameTimer& gt) {
	ThrowIfFailed(mDirectCmdListAlloc->Reset());

	ThrowIfFailed(mCommandList->Reset(mDirectCmdListAlloc.Get(), nullptr));

	mCommandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(CurrentBackBuffer(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET));

	mCommandList->RSSetViewports(1, &mScreenViewport);
	mCommandList->RSSetScissorRects(1, &mScissorRect);

	mCommandList->ClearRenderTargetView(CurrentBackBufferView(), Colors::Green, 0, nullptr);
	mCommandList->ClearDepthStencilView(DepthStencilView(), D3D12_CLEAR_FLAG_DEPTH | D3D12_CLEAR_FLAG_STENCIL, 1.0f, 0, 0, nullptr);

	mCommandList->OMSetRenderTargets(1, &CurrentBackBufferView(), true, &DepthStencilView());

	mCommandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(CurrentBackBuffer(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT));
	
	ThrowIfFailed(mCommandList->Close());

	ID3D12CommandList* cmdsLists[] = { mCommandList.Get() };
	mCommandQueue->ExecuteCommandLists(_countof(cmdsLists), cmdsLists);

	ThrowIfFailed(mSwapChain->Present(0, 0));
	mCurrBackBuffer = (mCurrBackBuffer + 1) % SwapChainBufferCount;

	FlushCommandQueue();


}
////////////////////////////////////////////////////////////////////////////////////////////////

int WINAPI WinMain(_In_  HINSTANCE hInstance, _In_opt_ HINSTANCE prevInstance, _In_ PSTR cmdLime, _In_ int showCmd) {
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	try {
		InitDirect3DApp theApp(hInstance);
		if (!theApp.Initialize())
			return 0;

		return theApp.Run();
	}
	catch (DxException& e) {
		MessageBox(nullptr, e.ToString().c_str(), L"HR Failed", MB_OK);
		return 0;
	}
}