package org.example.web;

import java.util.HashMap;
import java.util.Map;

import lombok.Getter;

@Getter
public class WebClient {
    private final HttpService httpService;

    private final Map<String,String> headers;

    private WebClient(HttpService httpService, Map<String,String> headers) {
        this.httpService = httpService;
        this.headers = headers;
    }

    public String getData(String url) {
        return httpService.get(url, headers);
    }

    static Map<String, String> getDefaultHeaders(){
        throw new UnsupportedOperationException("Some forgot about this or it just isn't initialized");
    }

    public static Builder builder() {
        return new Builder();
    }

    public static class Builder{
        private HttpService httpService;

        private Map<String,String> headers = new HashMap<>();

        public Builder httpService(HttpService httpService) {
            this.httpService = httpService;
            return this;
        }

        public Builder headers(Map<String,String> headers) {
            this.headers = headers;
            return this;
        }

        public Builder header(String key, String value) {
            headers.put(key,value);
            return this;
        }

        public WebClient build() {
            if (httpService == null) {
                throw new IllegalStateException("httpService not set");
            }
            if (headers == null) {
                headers = getDefaultHeaders();
            }

            return new WebClient(httpService, headers);
        }

    }
}

