#pragma once

#include "pch.h"

namespace Win_Media_Classic_Premium {
	value struct add_media;

	partial ref class MainPage {
	internal:
		static property Platform::String^ FEATURE_MEDIA_NAME {
			Platform::String^ get() {
				return "Media edit";
			}
		}

		static property Platform::Array<add_media>^ add_media_data_scn {
			Platform::Array<add_media> ^ get() {
				return inner;
			}
		}

	private:
		static Platform::Array<add_media>^ inner;
	};

	value struct add_media {
		Platform::String^ Title;
		Platform::String^ ClassName;
	};
}
