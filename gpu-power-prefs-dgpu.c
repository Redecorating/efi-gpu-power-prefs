#include <efi.h>
#include <efilib.h>

EFI_STATUS EFIAPI efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {

    const EFI_GUID applegpuGUID = { 0xfa4ce28d, 0xb62f, 0x4c99, {0x9c, 0xc3, 0x68, 0x15, 0x68, 0x6e, 0x30, 0xf9}};

    const UINT32 flags = EFI_VARIABLE_BOOTSERVICE_ACCESS|EFI_VARIABLE_RUNTIME_ACCESS|EFI_VARIABLE_NON_VOLATILE;

    static const char csrVal[4] = {0x00, 0x00, 0x00, 0x00};
   
    EFI_RUNTIME_SERVICES* rt; 

    InitializeLib(ImageHandle, SystemTable);
    rt = SystemTable->RuntimeServices;

    uefi_call_wrapper(rt->SetVariable, 5, L"gpu-power-prefs", &applegpuGUID, flags, 4, csrVal);

    uefi_call_wrapper(rt->ResetSystem, 4, EfiResetShutdown, EFI_SUCCESS, 0, NULL);

    return EFI_SUCCESS;
}
