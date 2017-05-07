#ifndef PSG_H
#define PSG_H
#include <osbind.h>
#define channelASize 128
#define channelBSize 12
struct note{
	int frequency;
	unsigned long duration;
	unsigned int volume;
};

void set_frequency(int channel, unsigned int value);

void write_psg(int reg, int val);

int read_psg(int reg);

void set_volume(int channel, int volume);

void enable_channel(int channel, int tone_on, int noise_on);

void stop_sound();

void set_envelope(int shape, unsigned int sustain);

void playGunShotSound();

void playJumpSound();

void start_music();

void update_music();

#endif