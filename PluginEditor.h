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

#ifndef __JUCE_HEADER_75A59D57586A7B89__
#define __JUCE_HEADER_75A59D57586A7B89__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"

/////////////OpenGL class for waveform display///////////////
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
class MyOpenGLCanvas  : public OpenGLAppComponent, public Timer
{
public:
    MyOpenGLCanvas();
    ~MyOpenGLCanvas();
    void newOpenGLContextCreated();
    void renderOpenGL();
    void timerCallback();
};
/////////////////////////////////////////////////////////////////

//[/Headers]

#include "MIDIContentComponent.h"

//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ISynthPluginAudioProcessorEditor : public AudioProcessorEditor,
                                         public Timer,
                                         public SliderListener,
                                         public ButtonListener,
                                         public ComboBoxListener
{
public:
    //==============================================================================
    ISynthPluginAudioProcessorEditor (ISynthPluginAudioProcessor* ownerFilter);
    ~ISynthPluginAudioProcessorEditor();
    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    ISynthPluginAudioProcessor* getProcessor()
    {return static_cast<ISynthPluginAudioProcessor*>(getAudioProcessor());}
    //[/UserMethods]
    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MyOpenGLCanvas* gl;
    //MidiMessageManager myMidi;
    //[/UserVariables]
    //==============================================================================
    ScopedPointer<Slider> slider;
    ScopedPointer<Slider> slider1;
    ScopedPointer<TextButton> textButton;
    ScopedPointer<ComboBox> comboBox;
    ScopedPointer<TextButton> textButton1;
    ScopedPointer<ComboBox> comboBox1;
    ScopedPointer<Slider> sliderA;
    ScopedPointer<Slider> sliderD;
    ScopedPointer<Slider> sliderS;
    ScopedPointer<Slider> sliderR;
    ScopedPointer<Slider> sliderCO;
    ScopedPointer<TextButton> textButtonF;
    ScopedPointer<Slider> sliderRES;
    ScopedPointer<ComboBox> comboBoxF;
    ScopedPointer<TextEditor> textEditor;
    ScopedPointer<TextEditor> textEditor2;
    ScopedPointer<TextButton> textButtonE;
    ScopedPointer<Slider> sliderLFO;
    ScopedPointer<Slider> sliderLFOMA;
    ScopedPointer<MIDIContentComponent> component2;
    ScopedPointer<TextEditor> textEditor3;
    ScopedPointer<ComboBox> comboBoxL;
    ScopedPointer<ComboBox> comboBoxLM;
    ScopedPointer<TextButton> textButtonE2;
    ScopedPointer<ComboBox> comboBoxSeq;
    ScopedPointer<TextEditor> textEditor4;
    ScopedPointer<Slider> sliderSeq;
    ScopedPointer<TextEditor> textEditor5;
    ScopedPointer<TextEditor> textEditor6;
    ScopedPointer<TextEditor> textEditor7;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ISynthPluginAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_75A59D57586A7B89__
