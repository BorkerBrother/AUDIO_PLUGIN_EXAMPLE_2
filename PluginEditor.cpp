#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 400);

    addAndMakeVisible(horizontalMeterL);
    addAndMakeVisible(horizontalMeterR);

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
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkgrey);

}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    horizontalMeterL.setBounds(100,100,200,15);
    horizontalMeterR.setBounds(100,120,200,15);
}
