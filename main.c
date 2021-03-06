/*
 * UEFI:SIMPLE - UEFI development made easy
 * Copyright � 2014 Pete Batard <pete@akeo.ie> - Public Domain
 * See COPYING for the full licensing terms.
 */
#include <efi.h>
#include <efilib.h>

// Appplication entrypoint
EFI_STATUS EfiMain(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
	EFI_INPUT_KEY Key;

	InitializeLib(ImageHandle, SystemTable);

	Print(L"\n*** UEFI:SIMPLE ***\n\n");

	Print(L"\nPress any key to exit.\n");
	SystemTable->ConIn->Reset(SystemTable->ConIn, FALSE);
	while (SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &Key) == EFI_NOT_READY);
#if defined(_DEBUG)
	// If running in debug mode, use the EFI shut down call to close QEMU
	RT->ResetSystem(EfiResetShutdown, EFI_SUCCESS, 0, NULL);
#endif

	return EFI_SUCCESS;
}
