package org.example.web;

import java.util.Map;

public interface HttpService {
    String get(String url, Map<String, String> headers);
}
