#include <curl/curl.h>

void get_profile(void);
void get_bands(void);
void get_posts(void);
void get_post(void);
void write_post(void);
void delete_post(void);
void get_comments(void);
void write_comment(void);
void delete_comment(void);
void get_permissions(void);
void get_albums(void);
void get_photos(void);

void http_get(const char *url, const char *parameters);
void http_post(const char *url, const char *parameters);

int main(void)
{
	curl_global_init(CURL_GLOBAL_ALL);

	get_profile();
	get_bands();
	get_posts();
	get_post();
	write_post();
	delete_post();
	get_comments();
	write_comment();
	delete_comment();
	get_permissions();
	get_albums();
	get_photos();

	curl_global_cleanup();

	return 0;
}

void get_profile(void)
{
	const char *url = "https://openapi.band.us/v2/profile";
	const char *parameters = "access_token=Your_Access_Token";
	http_get(url, parameters);
}

void get_bands(void)
{
	const char *url = "https://openapi.band.us/v2.1/bands";
	const char *parameters = "access_token=Your_Access_Token";
	http_get(url, parameters);
}

void get_posts(void)
{
	const char *url = "https://openapi.band.us/v2/band/posts";
	const char *parameters = "access_token=Your_Access_Token&band_key=Your_Band_Key&locale=Your_Locale";
	http_get(url, parameters);
}

void get_post(void)
{
	const char *url = "https://openapi.band.us/v2.1/band/post";
	const char *parameters = "access_token=Your_Access_Token&band_key=Your_Band_Key&post_key=Your_Post_key";
	http_get(url, parameters);
}

void write_post(void)
{
	const char *url = "https://openapi.band.us/v2.2/band/post/create";
	const char *parameters = "access_token=Your_Access_Token&band_key=Your_Band_Key&content=Your_Content";
	http_post(url, parameters);
}

void delete_post(void)
{
	const char *url = "https://openapi.band.us/v2/band/post/remove";
	const char *parameters = "access_token=Your_Access_Token&band_key=Your_Band_Key&post_key=Your_Post_key";
	http_post(url, parameters);
}

void get_comments(void)
{
	const char *url = "https://openapi.band.us/v2/band/post/comments";
	const char *parameters = "access_token=Your_Access_Token&band_key=Your_Band_Key&post_key=Your_Post_key";
	http_get(url, parameters);
}

void write_comment(void)
{
	const char *url = "https://openapi.band.us/v2/band/post/comment/create";
	const char *parameters = "access_token=Your_Access_Token&band_key=Your_Band_Key&post_key=Your_Post_key&body=Your_Comment";
	http_post(url, parameters);
}

void delete_comment(void)
{
	const char *url = "https://openapi.band.us/v2/band/post/comment/remove";
	const char *parameters = "access_token=Your_Access_Token&band_key=Your_Band_Key&post_key=Your_Post_key&comment_key=Your_Comment_Key";
	http_post(url, parameters);
}

void get_permissions(void)
{
	const char *url = "https://openapi.band.us/v2/band/permissions";
	const char *parameters = "access_token=Your_Access_Token&band_key=Your_Band_Key&permissions=Permissions_You_Want_To_Check";
	http_get(url, parameters);
}

void get_albums(void)
{
	const char *url = "https://openapi.band.us/v2/band/albums";
	const char *parameters = "access_token=Your_Access_Token&band_key=Your_Band_Key";
	http_get(url, parameters);
}

void get_photos(void)
{
	const char *url = "https://openapi.band.us/v2/band/album/photos";
	const char *parameters = "access_token=Your_Access_Token&band_key=Your_Band_Key";
	http_get(url, parameters);
}

void http_get(const char *url, const char *parameters)
{
	printf("\x1b[32mGET %s\n\x1b[0m", url);

	CURL *curl = curl_easy_init();

	CURLU *get_url = curl_url();
	curl_url_set(get_url, CURLUPART_URL, url, 0);
	curl_url_set(get_url, CURLUPART_QUERY, parameters, 0);
	curl_easy_setopt(curl, CURLOPT_CURLU, get_url);
	curl_easy_perform(curl);
	curl_url_cleanup(get_url);

	curl_easy_cleanup(curl);

	printf("\n\n");
}

void http_post(const char *url, const char *parameters)
{
	printf("\x1b[32mPOST %s\n\x1b[0m", url);

	CURL *curl = curl_easy_init();

	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_POST, 1L);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, parameters);
	curl_easy_perform(curl);

	curl_easy_cleanup(curl);

	printf("\n\n");
}
