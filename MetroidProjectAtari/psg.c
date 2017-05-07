#include "psg.h"
volatile char *PSG_reg_select = 0xFF8800;
volatile char *PSG_reg_write  = 0xFF8802;
int enable_channel_value = 0x3F;
int channelAPos = 0;
int channelBPos = 0;
int noteADurCount = 0;
int noteBDurCount = 0;
struct note channelA[channelASize] = {
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	{478,7,13}, /*C reg*/
	{568,7,13},
	
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	
	{478,7,13}, /*C reg*/
	{568,7,13},
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	{478,7,13}, /*C reg*/
	{568,7,13},
	
	/*end of bar 1*/
	
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	
	{478,7,13}, /*C reg*/
	{568,7,13},
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	{478,7,13}, /*C reg*/
	{568,7,13},
	
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	/* end of bar 2 */
	
	{478,7,13}, /*C reg*/
	{568,7,13},
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	{478,7,13}, /*C reg*/
	{568,7,13},
	
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	
	{478,7,13}, /*C reg*/
	{568,7,13},
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	/* end of bar 3 */
	
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	{478,7,13}, /*C reg*/
	{568,7,13},
	
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	
	{478,7,13}, /*C reg*/
	{568,7,13},
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	{478,7,13}, /*C reg*/
	{568,7,13},
	
	/* end of bar 4 */
	
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	
	{478,7,13}, /*C reg*/
	{568,7,13},
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	{478,7,13}, /*C reg*/
	{568,7,13},
	
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	
	/* end of bar 5 */
	
	{478,7,13}, /*C reg*/
	{568,7,13},
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	{478,7,13}, /*C reg*/
	{568,7,13},
	
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	
	{478,7,13}, /*C reg*/
	{568,7,13},
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	/* end of bar 6 */
	
	
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	{478,7,13}, /*C reg*/
	{568,7,13},
	
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	
	{478,7,13}, /*C reg*/
	{568,7,13},
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	{478,7,13}, /*C reg*/
	{568,7,13},
	
	/* end of bar 7 */
	
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	
	{478,7,13}, /*C reg*/
	{568,7,13},
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	{478,7,13}, /*C reg*/
	{568,7,13},
	
	{478,7,13}, /*C reg*/
	{402,7,13}, /*D sharp */
	{338,7,13}, /*F sharp */
	{402,7,13}, /*D sharp */
	
	/* end of bar 8 */
};

struct note channelB[channelBSize] = {
	{1136,112,7}, 
	{1204,61,7},
	{956,61,7},
	{1012,61,7}, 
	{1432,61,7}, 
	{1200,112,7}, 
	{1136,112,7}, 
	{1204,61,7},
	{1704,61,7},
	{1276,61,7},
	{1804,61,7},
	{1352,112,7}
};
/* Purpose: write a value into specified register
Parameters: reg (the register to write to), val (the value to write)
returns: none
*/
void write_psg(int reg, int val){/* requires super mode enabled*/
	*PSG_reg_select = reg;		
	*PSG_reg_write  = val;
}
/* Purpose: writes a frequency to a channel
Parameters: channel (the channel to write to), val (the frquency to write)
returns: none
*/
void set_frequency(int channel, unsigned int value){
	channel = channel << 1;
	*PSG_reg_select = channel;		
	*PSG_reg_write  = (value & 0x00FF);
	*PSG_reg_select = channel + 1;		
	*PSG_reg_write  = ((value & 0x0F00) >> 8);
}
/*Purpose: enable all music channels and run initalization for update music 
Parameters: none
Returns: none
*/
void start_music(){
	long old_ssp = Super(0);
	channelAPos = 0;
	enable_channel(0,1,0);
	enable_channel(1,1,0);
	set_volume(0,channelA[channelAPos].volume);
	noteADurCount += channelA[channelAPos].duration;
	set_frequency(0,channelA[channelAPos].frequency);
	set_volume(1,channelB[channelBPos].volume);
	noteBDurCount += channelB[channelBPos].duration;
	set_frequency(1,channelB[channelBPos].frequency);
	
	Super(old_ssp);
}
/*Purpose: updates the music by one frame each time it is called. depends on noteADurCount,noteBDurCount,channelA,channelB
Parameters: none
Returns: none
*/
void update_music(){
	noteADurCount--;
	noteBDurCount--;
	if(noteADurCount <= 0){
		channelAPos++;
		if(channelAPos == channelASize){
			channelAPos = 0;
		}
		noteADurCount += channelA[channelAPos].duration << 1;
		set_volume(0,channelA[channelAPos].volume);
		set_frequency(0,channelA[channelAPos].frequency);
	
	}
	if(noteBDurCount <= 0){
		channelBPos++;
		if(channelBPos == channelBSize){
			channelBPos = 0;
		}
		set_volume(1,channelB[channelBPos].volume);
		noteBDurCount += channelB[channelBPos].duration;
		set_frequency(1,channelB[channelBPos].frequency);
	
	}
}
/*Purpose: to read a certin value out of the register 
Parameter: reg (the register to be read)
Returns: the value in the specified register
*/
int read_psg(int reg){
	*PSG_reg_select = reg;
	return *PSG_reg_select;
} 
/* Purpose: set the volume of a specified channel 
Parameters: channel (the channel to write to), volume (the volume to set the channel to)
returns: none
*/
void set_volume(int channel, int volume){
	channel += 8;
	*PSG_reg_select = channel;				
	*PSG_reg_write  = volume;
}
/* Purpose: enable a specified channel
Parameters: channel (the channel to write to), tone_on (weither or not to enable tone), noise_on(weither or not to enable noise)
Returns: none*/
void enable_channel(int channel, int tone_on, int noise_on){
	int channel7Value = read_psg(7);
	int moveValue = ( 9 << channel);
	channel = (((noise_on << 3) | tone_on) << channel);
	channel7Value |= moveValue;
	channel7Value ^= channel;
	write_psg(7,channel7Value);
} 
/* Purpose: disable all audio channels
Parameters: none
Returns: none
*/
void stop_sound(){
	write_psg(7,0x3F);
}
/* Purpose: set the envelope shape and sustain
Parameters: shape (which shape to set the envelope see reference for options), sustain (how long the shape should last)
Returns: none
*/
void set_envelope(int shape, unsigned int sustain){
	write_psg(0x0D,shape);
	write_psg(0x0C,(sustain & 0xFF00) >> 8);
	write_psg(0x0B,sustain & 0x00FF);
}
/* Purpose: plays a gunshot sound NOTE: must not be in super during call.
Parameters: none
Returns: none
*/
void playGunShotSound(){
	long old_ssp = Super(0);

	write_psg(4,150);
	
	write_psg(5,0);
	
	write_psg(6,0x0F);

	enable_channel(2,1,0);
	
	set_volume(2,0x10);   /* set channel C */
	
	set_envelope(0,0x0700);
	Super(old_ssp);
}
/* Purpose: plays a jumping sound NOTE: must not be in super during call.
Parameters: none
Returns: none
*/
void playJumpSound(){
	long old_ssp = Super(0);

	write_psg(4,255);
	
	write_psg(5,1);
	
	write_psg(6,0x0F);

	enable_channel(2,1,0);
	
	set_volume(2,0x10);   /* set channel C */
	
	set_envelope(0,0x0700);
	
	Super(old_ssp);
}