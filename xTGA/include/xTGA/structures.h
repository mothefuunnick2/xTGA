//============ Copyright � 2019 Brett Anthony. All rights reserved. ============
///
/// This work is licensed under the terms of the MIT license.
/// For a copy, see <https://opensource.org/licenses/MIT>.
//==============================================================================
/// file 	: structures.h
/// purpose : Contains definitions for the header/footer/other structs that a TGA file contains.
//==============================================================================

#ifndef XTGA_STRUCTURES_H__
#define XTGA_STRUCTURES_H__

#include "xTGA/flags.h"
#include "xTGA/types.h"

namespace xtga
{
	namespace structs
	{
		struct ImageDescriptor
		{
			union
			{
				UChar RawBits;
				struct
				{
					UChar						ALPHA_CHANNEL	: 4;
					xtga::flags::IMAGEORIGIN	IMAGE_ORIGIN	: 2;
					UChar						UNUSED			: 2;
				};
			};
		};

		struct Header
		{
			UChar						ID_LENGTH;						/* Length of the Image ID Field (in bytes). */
			UChar						COLOR_MAP_TYPE;					/* 0 if there is no color map, 1 otherwise. */
			xtga::flags::IMAGETYPE		IMAGE_TYPE;						/* Image type. */
			UInt16						COLOR_MAP_FIRST_ENTRY_INDEX;	/* Index of the first color map entry. */
			UInt16						COLOR_MAP_LENGTH;				/* Total number of color map entries. */
			UChar						COLOR_MAP_BITS_PER_ENTRY;		/* Number of bits per color map entry. */
			UInt16						ORIGIN_X;						/* Absolute horizontal coordinate for the lower left corner of the image. */
			UInt16						ORIGIN_Y;						/* Absolute vertical coordinate for the lower left corner of the image. */
			UInt16						IMAGE_WIDTH;					/* Width of the image in pixels. */
			UInt16						IMAGE_HEIGHT;					/* Height of the image in pixels. */
			UChar						IMAGE_DEPTH;					/* Bits per pixel of the image. */
			ImageDescriptor				IMAGE_DESCRIPTOR;				/* Contains the number of attribute bits per pixel/alpha bits per pixel, and image origin. */
		};

		struct Footer
		{
			UInt32						EXTENSION_AREA_OFFSET;			/* Offset for the extension area. */
			UInt32						DEVELOPER_DIRECTORY_OFFSET;		/* Offset for the developer directory. */
			UChar						SIGNATURE[18];					/* Should always be "TRUEVISION-XFILE.\0" -- note that some implementations omit the final null-terminator. */
		};

		struct DeveloperDirectoryEntry
		{
			UInt16						TAG;							/* Identifies the type of devloper entry. */
			UInt32						ENTRY_OFFSET;					/* The offset of the entry (from start of file). */
			UInt32						ENTRY_SIZE;						/* Size of the entry (in bytes). */
		};

		struct ExtensionArea
		{
			UInt16						EXTENSION_SIZE;					/* The size of the extension area. Should be 495 for TGA 2.0. */
			UChar						AUTHOR_NAME[41];				/* The file author's name. Null-terminated. */
			UChar						AUTHOR_COMMENTS_0[81];			/* 1st author comment line. Null-terminated. */
			UChar						AUTHOR_COMMENTS_1[81];			/* 2nd author comment line. Null-terminated. */
			UChar						AUTHOR_COMMENTS_2[81];			/* 3rd author comment line. Null-terminated. */
			UChar						AUTHOR_COMMENTS_3[81];			/* 4th author comment line. Null-terminated. */
			UInt16						SAVE_DATE_MONTH;				/* The month the file was last saved/modified. */
			UInt16						SAVE_DATE_DAY;					/* The day the file was last saved/modified. */
			UInt16						SAVE_DATE_YEAR;					/* The year the file was last saved/modified. */
			UInt16						SAVE_DATE_HOUR;					/* The hour the file was last saved/modified. */
			UInt16						SAVE_DATE_MINUTE;				/* The minute the file was last saved/modified. */
			UInt16						SAVE_DATA_SECOND;				/* The second the file was last saved/modified. */
			UChar						JOB_NAME[41];					/* Name/ID tag for the image. Null-terminated. */
			UInt16						JOB_HOURS;						/* The amount of billed hours for the image. */
			UInt16						JOB_MINUTES;					/* The amount of billed minutes for the image. */
			UInt16						JOB_SECONDS;					/* The number of billed seconds for the image. */
			UChar						SOFTWARE_ID[41];				/* The software that was used to create the image. Null-terminated. */
			UInt16						SOFTWARE_VERSION;				/* The version of the software used to create the image. The version is multiplied by 100. i.e. for version 2.50, store 250. */
			UChar						SOFTWARE_LETTER;				/* The letter that is added to the end of the software version, i.e. 'b' for beta. */
			UInt32						KEY_COLOR;						/* The chroma key color for the image in format ARGB. */
			UInt32						SCAN_LINE_OFFSET;				/* The offset from the beginning of the file for the scan line table. */
			xtga::flags::ALPHATYPE		ALPHATYPE;						/* Details the type of alpha the image contains. */
		};
	}
}

#endif // !XTGA_STRUCTURES_H__
