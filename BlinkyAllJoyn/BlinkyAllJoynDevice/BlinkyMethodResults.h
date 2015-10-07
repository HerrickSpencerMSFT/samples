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
#pragma once

namespace com { namespace microsoft { namespace maker { namespace Blinky {

ref class BlinkyConsumer;

public ref class BlinkyStartResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    
    static BlinkyStartResult^ CreateSuccessResult()
    {
        auto result = ref new BlinkyStartResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        return result;
    }
    
    static BlinkyStartResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new BlinkyStartResult();
        result->Status = status;
        return result;
    }

private:
    int32 m_status;
};

public ref class BlinkyStopResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    
    static BlinkyStopResult^ CreateSuccessResult()
    {
        auto result = ref new BlinkyStopResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        return result;
    }
    
    static BlinkyStopResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new BlinkyStopResult();
        result->Status = status;
        return result;
    }

private:
    int32 m_status;
};

public ref class BlinkyJoinSessionResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    property BlinkyConsumer^ Consumer
    {
        BlinkyConsumer^ get() { return m_consumer; }
    internal:
        void set(_In_ BlinkyConsumer^ value) { m_consumer = value; }
    };

private:
    int32 m_status;
    BlinkyConsumer^ m_consumer;
};

public ref class BlinkyGetVersionResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    property uint16 Version
    {
        uint16 get() { return m_value; }
    internal:
        void set(_In_ uint16 value) { m_value = value; }
    }

    static BlinkyGetVersionResult^ CreateSuccessResult(_In_ uint16 value)
    {
        auto result = ref new BlinkyGetVersionResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->Version = value;
        return result;
    }

    static BlinkyGetVersionResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new BlinkyGetVersionResult();
        result->Status = status;
        return result;
    }

private:
    int32 m_status;
    uint16 m_value;
};

public ref class BlinkyGetBlinkIntervalResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    property double BlinkInterval
    {
        double get() { return m_value; }
    internal:
        void set(_In_ double value) { m_value = value; }
    }

    static BlinkyGetBlinkIntervalResult^ CreateSuccessResult(_In_ double value)
    {
        auto result = ref new BlinkyGetBlinkIntervalResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->BlinkInterval = value;
        return result;
    }

    static BlinkyGetBlinkIntervalResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new BlinkyGetBlinkIntervalResult();
        result->Status = status;
        return result;
    }

private:
    int32 m_status;
    double m_value;
};

public ref class BlinkySetBlinkIntervalResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    static BlinkySetBlinkIntervalResult^ CreateSuccessResult()
    {
        auto result = ref new BlinkySetBlinkIntervalResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        return result;
    }

    static BlinkySetBlinkIntervalResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new BlinkySetBlinkIntervalResult();
        result->Status = status;
        return result;
    }

private:
    int32 m_status;
};

public ref class BlinkyGetIsBlinkingResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    property bool IsBlinking
    {
        bool get() { return m_value; }
    internal:
        void set(_In_ bool value) { m_value = value; }
    }

    static BlinkyGetIsBlinkingResult^ CreateSuccessResult(_In_ bool value)
    {
        auto result = ref new BlinkyGetIsBlinkingResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->IsBlinking = value;
        return result;
    }

    static BlinkyGetIsBlinkingResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new BlinkyGetIsBlinkingResult();
        result->Status = status;
        return result;
    }

private:
    int32 m_status;
    bool m_value;
};

} } } } 
