package org.example.web;

import java.util.Map;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.Mock;
import org.mockito.MockedStatic;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.assertj.core.api.Assertions.assertThat;
import static org.assertj.core.api.Assertions.assertThatThrownBy;
import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.mockStatic;

@ExtendWith(MockitoExtension.class)
class WebClientTest {

    @Mock
    private HttpService httpService;

    @Test
    void testCreateWebClient() {
        WebClient webClient = WebClient.builder()
                .httpService(httpService)
                .build();
        assertNotNull(webClient);
    }

    @Test
    void testCreateWebClientNoHttpService() {
        assertThrows(IllegalStateException.class, ()-> WebClient.builder().build());
    }

    @Test
    void testCreateStaticMock() {
        WebClient.Builder builder = WebClient.builder();
        try(MockedStatic<WebClient> webClientMockedStatic = mockStatic(WebClient.class)){
            webClientMockedStatic.when(WebClient::getDefaultHeaders).thenReturn(Map.of());
            WebClient webClient = builder
                    .httpService(httpService)
                    .headers(null).build();
            assertNotNull(webClient);
        }
    }

    @Test
    void testCreateMapCheck() {
        WebClient builder = WebClient.builder()
                .httpService(httpService)
                .header("key1", "value1")
                .header("key2", "value2")
                .build();

        assertThat(builder.getHeaders())
                .isNotNull()
                .hasSize(2)
                .containsEntry("key1", "value1")
                .containsEntry("key2", "value2");
    }

    @Test
    void testCreateCheckExceptionMessage() {
        WebClient.Builder builder = WebClient.builder()
                .httpService(httpService)
                .headers(null);

        assertThatThrownBy(builder::build)
                .isInstanceOf(UnsupportedOperationException.class)
                .matches(exception->!exception.getMessage().isBlank())
                .hasMessageContaining("forgot about this")
                .satisfies((exception)->{
                    assertThat(exception.getMessage()).contains("forgot about this");
                });
    }
}