#ifndef RAGE_FILE_DRIVER_ZIP_H
#define RAGE_FILE_DRIVER_ZIP_H

#include "RageFileDriver.h"

struct FileInfo;
struct end_central_dir_record;
class RageFileDriverZip: public RageFileDriver
{
public:
	RageFileDriverZip( CString path );
	virtual ~RageFileDriverZip();

	RageFileObj *Open( const CString &path, int mode, int &err );
	void FlushDirCache( const CString &sPath );

private:
	RageFile zip;
    vector<FileInfo *> Files;

	void ParseZipfile();
	static void ReadEndCentralRecord( RageFile &zip, end_central_dir_record &ec );
	static int ProcessCdirFileHdr( RageFile &zip, FileInfo &info );
};

#endif

/*
 * Copyright (c) 1990-2002 Info-ZIP.  All rights reserved.
 * Copyright (c) 2003-2004 Glenn Maynard.  All rights reserved.
 * 
 * For the purposes of this copyright and license, "Info-ZIP" is defined as
 * the following set of individuals:
 * 
 *    Mark Adler, John Bush, Karl Davis, Harald Denker, Jean-Michel Dubois,
 *    Jean-loup Gailly, Hunter Goatley, Ian Gorman, Chris Herborth, Dirk Haase,
 *    Greg Hartwig, Robert Heath, Jonathan Hudson, Paul Kienitz, David Kirschbaum,
 *    Johnny Lee, Onno van der Linden, Igor Mandrichenko, Steve P. Miller,
 *    Sergio Monesi, Keith Owens, George Petrov, Greg Roelofs, Kai Uwe Rommel,
 *    Steve Salisbury, Dave Smith, Christian Spieler, Antoine Verheijen,
 *    Paul von Behren, Rich Wales, Mike White
 * 
 * This software is provided "as is," without warranty of any kind, express
 * or implied.  In no event shall Info-ZIP or its contributors be held liable
 * for any direct, indirect, incidental, special or consequential damages
 * arising out of the use of or inability to use this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 *     1. Redistributions of source code must retain the above copyright notice,
 *        definition, disclaimer, and this list of conditions.
 * 
 *     2. Redistributions in binary form (compiled executables) must reproduce
 *        the above copyright notice, definition, disclaimer, and this list of
 *        conditions in documentation and/or other materials provided with the
 *        distribution.  The sole exception to this condition is redistribution
 *        of a standard UnZipSFX binary as part of a self-extracting archive;
 *        that is permitted without inclusion of this license, as long as the
 *        normal UnZipSFX banner has not been removed from the binary or disabled.
 * 
 *     3. Altered versions--including, but not limited to, ports to new operating
 *        systems, existing ports with new graphical interfaces, and dynamic,
 *        shared, or static library versions--must be plainly marked as such
 *        and must not be misrepresented as being the original source.  Such
 *        altered versions also must not be misrepresented as being Info-ZIP
 *        releases--including, but not limited to, labeling of the altered
 *        versions with the names "Info-ZIP" (or any variation thereof, including,
 *        but not limited to, different capitalizations), "Pocket UnZip," "WiZ"
 *        or "MacZip" without the explicit permission of Info-ZIP.  Such altered
 *        versions are further prohibited from misrepresentative use of the
 *        Zip-Bugs or Info-ZIP e-mail addresses or of the Info-ZIP URL(s).
 * 
 *     4. Info-ZIP retains the right to use the names "Info-ZIP," "Zip," "UnZip,"
 *        "UnZipSFX," "WiZ," "Pocket UnZip," "Pocket Zip," and "MacZip" for its
 *        own source and binary releases.
 */

