
#include <idc.idc>

static fixAllOffsets( strtext)
{
	auto ea, offset;
	auto last;
	Message("Start\n");
	ea = FindText(0x40000, SEARCH_DOWN | SEARCH_REGEX, 0, 0, strtext);
	last = 0;
	while( ea != BADADDR && ea != last)
	{
		Message("%a\n", ea);
		OpOff(ea, 0, 0);
		last = ea;
		ea = FindText(ea+6, SEARCH_DOWN | SEARCH_REGEX, 0, 0, strtext);
	}
	Message("End\n");
}

static main() 
{
	//fixAllOffsets( "0x8F[89][0-9A-F][0-9A-F][0-9A-F][0-9A-F][0-9A-F]" );
	fixAllOffsets( "0x8F[BCDE][0-9A-F][0-9A-F][0-9A-F][0-9A-F][0-9A-F]" );
}


