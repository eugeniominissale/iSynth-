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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MIDIContentComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

//==============================================================================
MIDIContentComponent::MIDIContentComponent ()
:   lastInputIndex (0),
isAddingFromMidiInput (false),
startTime (Time::getMillisecondCounterHiRes() * 0.001)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (midiInputList = new ComboBox ("new combo box"));
    midiInputList->setTextWhenNoChoicesAvailable ("No MIDI Inputs Enabled");
    const StringArray midiInputs (MidiInput::getDevices());
    midiInputList->addItemList (midiInputs, 1);
    midiInputList->setEditableText (false);
    midiInputList->setJustificationType (Justification::centredLeft);
    midiInputList->setTextWhenNothingSelected (String::empty);
    midiInputList->addListener (this);

    for (int i = 0; i < midiInputs.size(); ++i)
    {
        if (deviceManager.isMidiInputEnabled (midiInputs[i]))
        {
            setMidiInput (i);
            break;
        }
    }

    // if no enabled devices were found just use the first one in the list
    if (midiInputList->getSelectedId() == 0)
        setMidiInput (0);

    /*addAndMakeVisible (keyboardComponent);
    keyboardState.addListener (this);*/

    addAndMakeVisible (midiMessagesBox = new TextEditor ("new text editor"));
    midiMessagesBox->setMultiLine (false);
    midiMessagesBox->setReturnKeyStartsNewLine (false);
    midiMessagesBox->setReadOnly (false);
    midiMessagesBox->setScrollbarsShown (true);
    midiMessagesBox->setCaretVisible (true);
    midiMessagesBox->setPopupMenuEnabled (true);
    midiMessagesBox->setText (String::empty);
}

MIDIContentComponent::~MIDIContentComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]


    //[Destructor]. You can add your own custom destruction code here..
    // keyboardState.removeListener (this);
    // deviceManager.removeMidiInputCallback (MidiInput::getDevices()[midiInputList.getSelectedItemIndex()], this);
    // midiInputList.removeListener (this);
    //[/Destructor]
}
//[/MiscUserDefs]

//==============================================================================

//==============================================================================
void MIDIContentComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MIDIContentComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    midiInputList->setBounds (32, 80, 150, 24);
    midiMessagesBox->setBounds (32, 40, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MIDIContentComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == midiInputList)
    {
        //[UserComboBoxCode_midiInputList] -- add your combo box handling code here..
        // mi metto in ascolto sulla periferica selezionata
            setMidiInput (midiInputList->getSelectedItemIndex());
        //[/UserComboBoxCode_midiInputList]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...


class IncomingMessageCallback   : public CallbackMessage
{
public:
    IncomingMessageCallback (MIDIContentComponent* o, const MidiMessage& m, const String& s)
    : owner (o), message (m), source (s)
    {}
    void messageCallback() override
    {
        if (owner != nullptr)
            owner->addMessageToList (message, source);
            }
    
    Component::SafePointer<MIDIContentComponent> owner;
    MidiMessage message;
    String source;
};

void MIDIContentComponent::postMessageToList (const MidiMessage& message, const String& source)
{
    (new IncomingMessageCallback (this, message, source))->post();
}

static String getMidiMessageDescription (const MidiMessage& m)
{
    if (m.isNoteOn())           return "Note on "  + MidiMessage::getMidiNoteName (m.getNoteNumber(), true, true, 3);
    if (m.isNoteOff())          return "Note off " + MidiMessage::getMidiNoteName (m.getNoteNumber(), true, true, 3);
    if (m.isProgramChange())    return "Program change " + String (m.getProgramChangeNumber());
    if (m.isPitchWheel())       return "Pitch wheel " + String (m.getPitchWheelValue());
    if (m.isAftertouch())       return "After touch " + MidiMessage::getMidiNoteName (m.getNoteNumber(), true, true, 3) +  ": " + String (m.getAfterTouchValue());
    if (m.isChannelPressure())  return "Channel pressure " + String (m.getChannelPressureValue());
    if (m.isAllNotesOff())      return "All notes off";
    if (m.isAllSoundOff())      return "All sound off";
    if (m.isMetaEvent())        return "Meta event";
    
    if (m.isController())
    {
        String name (MidiMessage::getControllerName (m.getControllerNumber()));
        
        if (name.isEmpty())
            name = "[" + String (m.getControllerNumber()) + "]";
        
        return "Controller " + name + ": " + String (m.getControllerValue());
    }
    return String::toHexString (m.getRawData(), m.getRawDataSize());
}

void MIDIContentComponent::addMessageToList (const MidiMessage& message, const String& source)
{
    
    /*message.NOTE(MIDITOFREQ)*/

    const double time = message.getTimeStamp() - startTime;
    
    const int hours = ((int) (time / 3600.0)) % 24;
    const int minutes = ((int) (time / 60.0)) % 60;
    const int seconds = ((int) time) % 60;
    const int millis = ((int) (time * 1000.0)) % 1000;
    
    const String timecode (String::formatted ("%02d:%02d:%02d.%03d",
                                              hours,
                                              minutes,
                                              seconds,
                                              millis));
    
    const String description (getMidiMessageDescription (message));
    //const String midiMessageString (timecode + "  -  " + description + " (" + source + ")");
    //const String midiMessageString (String(MidiMessage::getMidiNoteInHertz(message.getPitchWheelValue())));
    //const String midiMessageString (String(message.getNoteNumber()));
    const String midiMessageString (String((440.0 * pow(2.0, (message.getNoteNumber() - 69.0)/12.0))));
    logMessage (midiMessageString);
}

void MIDIContentComponent::setMidiInput (int index)
{
    const StringArray list (MidiInput::getDevices());

    deviceManager.removeMidiInputCallback (list[lastInputIndex], this);

    const String newInput (list[index]);

    if (!deviceManager.isMidiInputEnabled (newInput))
        deviceManager.setMidiInputEnabled (newInput, true);

    deviceManager.addMidiInputCallback (newInput, this);
    midiInputList->setSelectedId (index + 1, dontSendNotification);

    lastInputIndex = index;
}

void MIDIContentComponent::handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message)
{
    const ScopedValueSetter<bool> scopedInputFlag (isAddingFromMidiInput, true);
    keyboardState.processNextMidiEvent (message);
    postMessageToList (message, source->getName());
}


void MIDIContentComponent::logMessage (const String& m)
{
    midiMessagesBox->moveCaretToEnd();
    midiMessagesBox->insertTextAtCaret (m + newLine);
}

/*override*/
void MIDIContentComponent::handleNoteOn (MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity)
{
    if (! isAddingFromMidiInput)
    {
        MidiMessage m (MidiMessage::noteOn (midiChannel, midiNoteNumber, velocity));
        m.setTimeStamp (Time::getMillisecondCounterHiRes() * 0.001);
        postMessageToList (m, "On-Screen Keybaord");
    }
}

void MIDIContentComponent::handleNoteOff (MidiKeyboardState*, int midiChannel, int midiNoteNumber)
{
    if (! isAddingFromMidiInput)
    {
        MidiMessage m (MidiMessage::noteOff (midiChannel, midiNoteNumber));
        m.setTimeStamp (Time::getMillisecondCounterHiRes() * 0.001);
        postMessageToList (m, "On-Screen Keyboard");
    }
}


// This is used to dispach an incoming message to the message thread






//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MIDIContentComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <COMBOBOX name="new combo box" id="6b588d7fd78cbafc" memberName="midiInputList"
            virtualName="" explicitFocusOrder="0" pos="32 80 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTEDITOR name="new text editor" id="7b52cb17d932ef17" memberName="midiMessagesBox"
              virtualName="" explicitFocusOrder="0" pos="32 40 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
