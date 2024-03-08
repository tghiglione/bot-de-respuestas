#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Herta.hpp"

class HertaTest : public ::testing::Test {
protected:
    const std::string RESPUESTA_AUTOMATICA = "[Respuesta automatica] Hola. En este momento no estoy disponible, "
                                             "y no me pondre en contacto contigo mas tarde.\n";
    const std::string RESPUESTAS_KURU[3] = {"KURU\n", "KURURIN\n", "KURU KURU\n"};
    const std::string RESPUESTA_HOLA = "Hola.\n";
    const std::string RESPUESTA_PROBLEMA = "No te preocupes. Ya esta solucionado.\n";
    const std::string RESPUESTA_PREOCUPADO = "De que te preocupas si yo estoy aqui?\n";
    const std::string RESPUESTA_SIMULADO = "La actualizacion del Universo Simulado ya esta lista, ven a probarla.\n";
    const std::string RESPUESTA_ERES_HERTA = "Quieres una selfie para demostrartelo o que?\n";
    const std::string RESPUESTA_MARIONETA = "Vaya, parece que la perdi. No me extrania que no la encuentre.\n";
    const std::string RESPUESTAS_INDETERMINADO[2] = {"Oh.\n", "...\n"};

    Herta herta{};
    std::string respuesta{};

    static std::string capturar_respuesta(Herta& herta, std::string mensaje);

    void SetUp() override;
};

std::string HertaTest::capturar_respuesta(Herta& herta, std::string mensaje) {
    testing::internal::CaptureStdout();
    herta.responder(mensaje);
    return testing::internal::GetCapturedStdout();
}

void HertaTest::SetUp() {
    capturar_respuesta(herta, "");
}

TEST_F(HertaTest, LaPrimeraRespuestaEsAutomatica) {
    Herta herta1;
    respuesta = capturar_respuesta(herta1, "hola");
    ASSERT_EQ(respuesta, RESPUESTA_AUTOMATICA);
}

TEST_F(HertaTest, HertaRespondeCincoMensajesDeFormaManual) {
    for (int _ = 1; _ <= 5; _++) {
        respuesta = capturar_respuesta(herta, "hola");
        ASSERT_EQ(respuesta, RESPUESTA_HOLA);
    }
}

TEST_F(HertaTest, DespuesDeCincoRespuestasManualesLaRespuestaEsAutomatica) {
    for (int _ = 1; _ <= 5; _++) {
        capturar_respuesta(herta, "");
    }
    respuesta = capturar_respuesta(herta, "hola");
    ASSERT_EQ(respuesta, RESPUESTA_AUTOMATICA);
}

TEST_F(HertaTest, RespuestaManualKuruKururin) {
    respuesta = capturar_respuesta(herta, "kuru");
    ASSERT_THAT(RESPUESTAS_KURU, testing::Contains(respuesta));

    respuesta = capturar_respuesta(herta, "kururin");
    ASSERT_THAT(RESPUESTAS_KURU, testing::Contains(respuesta));
}

TEST_F(HertaTest, RespuestaManualKuruKururinNoEsCaseSensitive) {
    respuesta = capturar_respuesta(herta, "KURU");
    ASSERT_THAT(RESPUESTAS_KURU, testing::Contains(respuesta));

    respuesta = capturar_respuesta(herta, "KURURIN");
    ASSERT_THAT(RESPUESTAS_KURU, testing::Contains(respuesta));
}

TEST_F(HertaTest, RespuestaManualHola) {
    respuesta = capturar_respuesta(herta, "hola");
    ASSERT_EQ(respuesta, RESPUESTA_HOLA);
}

TEST_F(HertaTest, RespuestaManualHolaNoEsCaseSensitive) {
    respuesta = capturar_respuesta(herta, "HoLa");
    ASSERT_EQ(respuesta, RESPUESTA_HOLA);
}

TEST_F(HertaTest, RespuestaManualProblema) {
    respuesta = capturar_respuesta(herta, "problema");
    ASSERT_EQ(respuesta, RESPUESTA_PROBLEMA);
}

TEST_F(HertaTest, RespuestaManualProblemaNoEsCaseSensitive) {
    respuesta = capturar_respuesta(herta, "ProBleMa");
    ASSERT_EQ(respuesta, RESPUESTA_PROBLEMA);
}

TEST_F(HertaTest, RespuestaManualPreocupado) {
    respuesta = capturar_respuesta(herta, "preocupado");
    ASSERT_EQ(respuesta, RESPUESTA_PREOCUPADO);

    respuesta = capturar_respuesta(herta, "preocupada");
    ASSERT_EQ(respuesta, RESPUESTA_PREOCUPADO);
}

TEST_F(HertaTest, RespuestaManualPreocupadoNoEsCaseSensitive) {
    respuesta = capturar_respuesta(herta, "PreOcuPaDo");
    ASSERT_EQ(respuesta, RESPUESTA_PREOCUPADO);

    respuesta = capturar_respuesta(herta, "PreOcuPaDa");
    ASSERT_EQ(respuesta, RESPUESTA_PREOCUPADO);
}

TEST_F(HertaTest, RespuestaManualSimulado) {
    respuesta = capturar_respuesta(herta, "simulado");
    ASSERT_EQ(respuesta, RESPUESTA_SIMULADO);
}

TEST_F(HertaTest, RespuestaManualSimuladoNoEsCaseSensitive) {
    respuesta = capturar_respuesta(herta, "SimuLaDo");
    ASSERT_EQ(respuesta, RESPUESTA_SIMULADO);
}

TEST_F(HertaTest, RespuestaManualEresHerta) {
    respuesta = capturar_respuesta(herta, "Eres Herta?");
    ASSERT_EQ(respuesta, RESPUESTA_ERES_HERTA);
}

TEST_F(HertaTest, RespuestaManualEresHertaNoEsCaseSensitive) {
    respuesta = capturar_respuesta(herta, "ERES HERTA?");
    ASSERT_EQ(respuesta, RESPUESTA_ERES_HERTA);
}

TEST_F(HertaTest, RespuestaManualEresHertaElMensajeDebeSerExacto) {
    respuesta = capturar_respuesta(herta, "Eres Herta??");
    ASSERT_THAT(RESPUESTAS_INDETERMINADO, testing::Contains(respuesta));
}

TEST_F(HertaTest, RespuestaManualMarioneta) {
    respuesta = capturar_respuesta(herta, "Y tu marioneta?");
    ASSERT_EQ(respuesta, RESPUESTA_MARIONETA);
}

TEST_F(HertaTest, RespuestaManualMarionetaNoEsCaseSensitive) {
    respuesta = capturar_respuesta(herta, "Y TU MARIONETA?");
    ASSERT_EQ(respuesta, RESPUESTA_MARIONETA);
}

TEST_F(HertaTest, RespuestaManualMarionetaElMensajeDebeSerExacto) {
    respuesta = capturar_respuesta(herta, "Y tu marioneta??");
    ASSERT_THAT(RESPUESTAS_INDETERMINADO, testing::Contains(respuesta));
}

TEST_F(HertaTest, RespuestaManualIndeterminado) {
    respuesta = capturar_respuesta(herta, "...");
    ASSERT_THAT(RESPUESTAS_INDETERMINADO, testing::Contains(respuesta));
}

TEST_F(HertaTest, PrioridadRespuestaManualKuru) {
    respuesta = capturar_respuesta(herta, "kuru hola problema preocupado simulado");
    ASSERT_THAT(RESPUESTAS_KURU, testing::Contains(respuesta));
}

TEST_F(HertaTest, PrioridadRespuestaManualHola) {
    respuesta = capturar_respuesta(herta, "hola problema preocupado simulado");
    ASSERT_EQ(respuesta, RESPUESTA_HOLA);
}

TEST_F(HertaTest, PrioridadRespuestaManualProblema) {
    respuesta = capturar_respuesta(herta, "problema preocupado simulado");
    ASSERT_EQ(respuesta, RESPUESTA_PROBLEMA);
}

TEST_F(HertaTest, PrioridadRespuestaManualPreocupado) {
    respuesta = capturar_respuesta(herta, "preocupado simulado");
    ASSERT_EQ(respuesta, RESPUESTA_PREOCUPADO);
}