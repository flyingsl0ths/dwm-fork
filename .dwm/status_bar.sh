#!/bin/sh

kill_existing() {
    instance_pid="$(pgrep -fo "/bin/sh /home/flyingsl0ths/.dwm/status_bar.sh")"

    if [ "$instance_pid" != "$$" ]; then
        kill -KILL "$instance_pid"
    fi
}

status_bar() {
    wifi_connection="[^c#50FA7B^  ^c#F8F8F2^$(nmcli -t -f name connection show --active | awk '{print $1}')]"

    ram_usage="[^c#F1FA8C^  ^c#F8F8F2^$(free -h --si | grep Mem | awk '{print ($3)}')]"

    todays_date="[^c#FFB86C^  ^c#F8F8F2^$(date +"%b %d, %Y %a %I:%M%p")]"

    battery_level="[^c#8BE9FD^  ^c#F8F8F2^$(cat /sys/class/power_supply/BAT1/capacity)%]"

    volume_level="[^c#BD93F9^  ^c#F8F8F2^$(pamixer --get-volume-human)]"

    xsetroot -name "$wifi_connection $ram_usage $todays_date $battery_level $volume_level"
}

kill_existing

while true; do
    status_bar
    sleep 1
done
