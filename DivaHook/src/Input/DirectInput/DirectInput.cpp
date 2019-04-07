#include "DirectInput.h"

namespace DivaHook::Input
{
	IDirectInput8 *IDirectInputInstance;

	HRESULT InitializeDirectInput(HMODULE module)
	{
		HRESULT result = DirectInput8Create(module, DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&IDirectInputInstance, nullptr);
		return result;
	}

	void DisposeDirectInput()
	{
		if (IDirectInputInstance == nullptr)
			return;

		IDirectInputInstance->Release();
		IDirectInputInstance = nullptr;
	}
}