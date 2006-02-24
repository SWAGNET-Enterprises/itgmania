/* ScreenMessage - Definition of common ScreenMessages. */

#ifndef SCREEN_MESSAGE_H
#define SCREEN_MESSAGE_H

#include <map>

typedef int ScreenMessage;

extern const ScreenMessage SM_Invalid;
extern const ScreenMessage SM_None;
extern const ScreenMessage SM_MenuTimer;
extern const ScreenMessage SM_DoneFadingIn;
extern const ScreenMessage SM_BeginFadingOut;
extern const ScreenMessage SM_GoToNextScreen;
extern const ScreenMessage SM_GoToPrevScreen;
extern const ScreenMessage SM_GainFocus;
extern const ScreenMessage SM_LoseFocus;
extern const ScreenMessage SM_Pause;
extern const ScreenMessage SM_Success;
extern const ScreenMessage SM_Failure;

class ASMHClass
{
public:
	ScreenMessage ToMessageNumber( const RString & Name );
	RString	NumberToString( ScreenMessage SM ) const;

private:
	map<RString, ScreenMessage> *m_pScreenMessages;
	ScreenMessage m_iCurScreenMessage;
};

extern ASMHClass AutoScreenMessageHandler;

// Automatically generate a unique ScreenMessage value
#define AutoScreenMessage( x ) \
	const ScreenMessage x = AutoScreenMessageHandler.ToMessageNumber( #x );


#endif

/*
 * (c) 2003-2005 Chris Danford, Charles Lohr
 * All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF
 * THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS
 * INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
