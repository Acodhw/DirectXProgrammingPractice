#include "Common/d3dApp.h"
#include "Common/MathHelper.h"
#include "Common/UploadBuffer.h"

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;

/*
* typedef struct D3D12_INPUT_ELEMENT_DESC
* {
*	LPCSTR SemanticName;						// ���� ���ڿ� �̸�
*	UINT semanticIndex;							// ���� �ε���
*	DXGI_FORMAT Format;							// ���� ������ �ڷ���
*	UINT InputSlot;								// ���� ���� ���� �ε���
*	UINT ALignedByteOffset;						// ���� ������ ��ġ ������
*	D3D12_INPUT_CLASSIFICATION InputSlotClass;	// D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA
*	UINT InstanceDataStepRate;					// 0
* } D3D12_INPUT_ELEMENT_DESC;
*/

struct Vertex {
	XMFLOAT3 Pos; // ��ġ
	XMFLOAT4 Color; // ��
}; // ���� ����ü

struct ObjectConstants {
	XMFLOAT4X4 WorldViewProj = MathHelper::Identity4x4(); //���� ��ȯ ���(�ʱⰪ : �⺻���)
};

// DirectX �ʱ�ȭ Ŭ���� �����
class PointApp : public D3DApp {
public:
	PointApp(HINSTANCE hInstance);
	PointApp(const PointApp& rhs) = delete;
	PointApp& operator=(const PointApp& rhs) = delete;
	~PointApp();

	virtual bool Initialize()override;

private:
	virtual void OnResize()override; // ȭ���� ũŰ�� �ٲ� �� ����
	virtual void Update(const GameTimer& gt)override; // 1�����Ӵ� ����
	virtual void Draw(const GameTimer& gt)override; // ȭ�鿡 ���𰡸� �׸� �� ����

	virtual void OnMouseDown(WPARAM btnState, int x, int y)override; // Event : ���콺 Ŭ��
	virtual void OnMouseUp(WPARAM btnState, int x, int y)override; // Event : ���콺 ��ư ����
	virtual void OnMouseMove(WPARAM btnState, int x, int y)override; // Event : ���콺 ������

	void BuildDescriptorHeaps(); 
	void BuildConstantBuffers();
	void BuildRootSignature();
	void BuildShadersAndInputLayout();
	void BuildBoxGeometry();
	void BuildPSO();

	/////////////////////////////////////////////////////////////
private:
	ComPtr<ID3D12RootSignature> mRootSignature = nullptr;
	ComPtr<ID3D12DescriptorHeap> mCbvHeap = nullptr;

	std::unique_ptr<UploadBuffer<ObjectConstants>> mObjectCB = nullptr;

	std::unique_ptr<MeshGeometry> mBoxGeo = nullptr;

	ComPtr<ID3DBlob> mvsByteCode = nullptr;
	ComPtr<ID3DBlob> mpsByteCode = nullptr;

	std::vector<D3D12_INPUT_ELEMENT_DESC> mInputLayout;

	ComPtr<ID3D12PipelineState> mPSO = nullptr;

	XMFLOAT4X4 mWorld = MathHelper::Identity4x4();
	XMFLOAT4X4 mView = MathHelper::Identity4x4();
	XMFLOAT4X4 mProj = MathHelper::Identity4x4();

	float mTheta = 1.5f * XM_PI;
	float mPhi = XM_PIDIV4;
	float mRadius = 5.0f;

	POINT mLastMousePos;
};