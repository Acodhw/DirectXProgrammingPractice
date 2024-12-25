#include "Common/d3dApp.h"
#include "Common/MathHelper.h"
#include "Common/UploadBuffer.h"

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;

struct Vertex {
	XMFLOAT3 pos; // ��ġ
	XMFLOAT3 normal; // ���� ��������
	XMFLOAT2 Tex0; // �ؽ��� ��ǥ
	XMFLOAT2 Tex1;
}; // ���� ����ü

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
D3D12_INPUT_ELEMENT_DESC vertexDesc[] = {
	{" POSITION ", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
	{" NORMAL ", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
	{" TEXCOORD ", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 24, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
	{" TEXCOORD ", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 32, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
};


