#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 300);

    addAndMakeVisible(horizontalMeterL);
    addAndMakeVisible(horizontalMeterR);


    addAndMakeVisible(verticalGradientMeterL);
    addAndMakeVisible(verticalGradientMeterR);

    startTimerHz(60);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

void AudioPluginAudioProcessorEditor::timerCallback()
{
    horizontalMeterL.setLevel(processorRef.getRmsValue(0));
    horizontalMeterR.setLevel(processorRef.getRmsValue(1));

    horizontalMeterL.repaint();
    horizontalMeterR.repaint();

    verticalGradientMeterL.repaint();
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    //g.fillAll(juce::Colours::darkgrey);

    juce::Rectangle<int> boundsArea1,boundsArea2,boundsArea3,boundsArea4;

    boundsArea1.setBounds(0,0,200,300);
    g.setColour(juce::Colours::darkgrey);
    g.fillRect(boundsArea1);

    boundsArea2.setBounds(200,0,200,300);
    g.setColour(juce::Colours::blueviolet);
    g.fillRect(boundsArea2);


    boundsArea3.setBounds(400,0,200,300);
    g.setColour(juce::Colours::black);
    g.fillRect(boundsArea3);

    boundsArea4.setBounds(600,0,200,300);
    g.setColour(juce::Colours::grey);
    g.fillRect(boundsArea4);




}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    //horizontalMeterL.setBounds(100,100,200,15);
    //horizontalMeterR.setBounds(100,120,200,15);

    verticalGradientMeterR.setBounds(480,50,15,200);
    verticalGradientMeterL.setBounds(520,50,15,200);
}
