/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_7852EB9DFF14C52A__
#define __JUCE_HEADER_7852EB9DFF14C52A__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"


//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MIDIContentComponent  :
public Component,
private ComboBox::Listener,
private MidiInputCallback,
private MidiKeyboardStateListener

{
public:
    //==============================================================================
    MIDIContentComponent ();
    ~MIDIContentComponent();
    //==============================================================================
    
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setMidiInput (int index);
    void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message);
    void logMessage (const String& m);
    void handleNoteOn (MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity);
    void handleNoteOff (MidiKeyboardState*, int midiChannel, int midiNoteNumber);
    void postMessageToList (const MidiMessage& message, const String& source);
    void addMessageToList (const MidiMessage& message, const String& source);
    //[/UserMethods]
    
    void paint (Graphics& g);
    void resized();
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    AudioDeviceManager deviceManager; //trova periferiche midi connesse
    Label midiInputListLabel;
    int lastInputIndex; //disattivo la periferica corrente quando ne seleziono una nuova
    bool isAddingFromMidiInput; //flag: indica che arriva un dato midi da una sorgente esterna
    MidiKeyboardState keyboardState; //tiene traccia di quale tastiera MIDI
    //MidiKeyboardComponent keyboardComponent;
    double startTime;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ComboBox> midiInputList;
    ScopedPointer<TextEditor> midiMessagesBox;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MIDIContentComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_7852EB9DFF14C52A__
