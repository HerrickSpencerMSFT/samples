//-----------------------------------------------------------------------------
// <auto-generated> 
//   This code was generated by a tool. 
// 
//   Changes to this file may cause incorrect behavior and will be lost if  
//   the code is regenerated.
//
//   Tool: AllJoynCodeGenerator.exe
//
//   This tool is located in the Windows 10 SDK and the Windows 10 AllJoyn 
//   Visual Studio Extension in the Visual Studio Gallery.  
//
//   The generated code should be packaged in a Windows 10 C++/CX Runtime  
//   Component which can be consumed in any UWP-supported language using 
//   APIs that are available in Windows.Devices.AllJoyn.
//
//   Using AllJoynCodeGenerator - Invoke the following command with a valid 
//   Introspection XML file and a writable output directory:
//     AllJoynCodeGenerator -i <INPUT XML FILE> -o <OUTPUT DIRECTORY>
// </auto-generated>
//-----------------------------------------------------------------------------
#include "pch.h"

using namespace concurrency;
using namespace Windows::Devices::AllJoyn;
using namespace Windows::UI::Core;
using namespace Microsoft::WRL;
using namespace Platform;

alljoyn_busattachment AllJoynHelpers::GetInternalBusAttachment(_In_ AllJoynBusAttachment^ busAttachment)
{
	ComPtr<IUnknown> iUnknown = reinterpret_cast<IUnknown*>(busAttachment);
	ComPtr<IWindowsDevicesAllJoynBusAttachmentInterop> interop;
	iUnknown.As(&interop);
	UINT64 win32handle;
	interop->get_Win32Handle(&win32handle);
	return reinterpret_cast<alljoyn_busattachment>(win32handle);
}

String^ AllJoynHelpers::MultibyteToPlatformString(_In_ PCSTR str)
{
	size_t length = strlen(str);

	UINT32 requiredBytes = MultiByteToWideChar(
		CP_UTF8,
		0,
		str,
		(int)length,
		nullptr,
		0);

	if (requiredBytes == 0)
	{
		return ref new String();
	}

	std::vector<wchar_t> buffer(requiredBytes + 1);

	UINT32 convertedBytes = MultiByteToWideChar(
		CP_UTF8,
		0,
		str,
		(int)length,
		(LPWSTR)&buffer[0],
		requiredBytes);

	buffer[convertedBytes] = '\0';
	return ref new String(&buffer[0]);
}

std::vector<char> AllJoynHelpers::PlatformToMultibyteString(_In_ String^ str)
{
	UINT32 requiredBytes = WideCharToMultiByte(
		CP_UTF8,
		WC_ERR_INVALID_CHARS,
		str->Data(),
		str->Length(),
		nullptr,
		0,
		nullptr,
		nullptr);

	if (requiredBytes == 0)
	{
		return std::vector<char>();
	}

	std::vector<char> buffer(requiredBytes + 1);

	UINT32 convertedBytes = WideCharToMultiByte(
		CP_UTF8,
		WC_ERR_INVALID_CHARS,
		str->Data(),
		str->Length(),
		(LPSTR)&buffer[0],
		requiredBytes,
		nullptr,
		nullptr);

	buffer[convertedBytes] = '\0';
	return buffer;
}

QStatus AllJoynHelpers::CreateInterfaces(_Inout_ AllJoynBusAttachment^ busAttachment, _In_ PCSTR introspectionXml)
{
	return alljoyn_busattachment_createinterfacesfromxml(AllJoynHelpers::GetInternalBusAttachment(busAttachment), introspectionXml);
}

Platform::String^ AllJoynHelpers::GetObjectPath(_In_ alljoyn_aboutobjectdescription objectDescription, _In_ PCSTR interfaceName)
{
	PCSTR path;
	if (alljoyn_aboutobjectdescription_getinterfacepaths(objectDescription, interfaceName, &path, 1) == 0)
	{
		return nullptr;
	}

	return AllJoynHelpers::MultibyteToPlatformString(path);
}

bool AllJoynHelpers::CanSecure(_In_ Windows::Foundation::Collections::IVector<Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism>^ authenticationMechanisms)
{
	unsigned int noneMechanismIndex = 0;
	bool authenticationMechanismsContainsNone = false;

	// If there are no AuthenticationMechanisms, authentication 
	// cannot be performed.
	if ((nullptr == authenticationMechanisms) || (authenticationMechanisms->Size == 0))
	{
		return false;
	}

	// If authenticationMechanisms contains one or more secure entries, 
	// authentication can be performed.
	authenticationMechanismsContainsNone = authenticationMechanisms->IndexOf(AllJoynAuthenticationMechanism::None, &noneMechanismIndex);
	if (false == authenticationMechanismsContainsNone)
	{
		return true;
	}

	// If authenticationMechanisms contains any secure mechanisms, 
	// authentication can be performed.
	for (auto authenticationMechanism : authenticationMechanisms)
	{
		if (authenticationMechanism != AllJoynAuthenticationMechanism::None)
		{
			return true;
		}
	}

	// If this point is reached, authentication cannot be performed
	// because no secure mechanisms are specified.
	return false;
}

void AllJoynHelpers::DispatchEvent(std::function<void()> callback)
{
	// Obtain a reference to the application's CoreDispatcher which allows 
	// us to run code on its UI thread, then run the provided callback.
	try
	{ 
		CoreDispatcher^ uiDispatcher = Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher;
		create_task([=]() {
			return uiDispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler(callback));
		}).wait();
	}
	catch (...)
	{
		callback();
		return;
	}
}
